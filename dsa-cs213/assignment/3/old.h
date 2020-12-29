#include<iostream>

class quad_tree{
    long long n;
    long long width;
    int data;
    long long x, y;
    quad_tree *nw, *ne, *sw, *se;

    bool allEqual(int &a, int &b, int &c, int &d){
        if( (a==b) && (b==c) && (c==d) ) return true;
        return false;
    }

    void makeChild(){
        nw = new quad_tree(n-1, data, x, y);
        ne = new quad_tree(n-1, data, x+width/2, y);
        sw = new quad_tree(n-1, data, x, y+width/2);
        se = new quad_tree(n-1, data, x+width/2, y+width/2);
    }

    void deleteChild(){
        if(nw != NULL) delete nw;
        if(ne != NULL) delete ne;
        if(sw != NULL) delete sw;
        if(se != NULL) delete se;
        return; 
    }

    void overlapUtil(int i){
        data = (data | i);
        if(nw != NULL){
            nw->overlapUtil(i);
            ne->overlapUtil(i);
            sw->overlapUtil(i);
            se->overlapUtil(i);
        }
        return;
    }

    void intersectUtil(int i){
        data = (data & i);
        if(nw != NULL){
            nw->intersectUtil(i);
            ne->intersectUtil(i);
            sw->intersectUtil(i);
            se->intersectUtil(i);
        }
        return;
    }

    long long ones(){
        if(nw == NULL){
            long long value = data;
            return value*(width*width);
        }
        return (nw->ones() + ne->ones() + sw->ones() + se->ones());
    }

    void Rutil1(int m, long long w, int d){
        // m > n
        n += d;
        x *= w;
        y *= w;
        width *= w;

        if(nw != NULL){
            nw->Rutil1(m-1, w, d);
            ne->Rutil1(m-1, w, d);
            sw->Rutil1(m-1, w, d);
            se->Rutil1(m-1, w, d);
        }
        return;        
    }

    void Rutil2(int m, long long w, int d){
        // m < n
        n -= d;
        x /= w;
        y /= w;
        
        if(n == 0){
            long long one = ones();
            long long total = w*w;
            long long occ;
            if(2*one >= total) occ = 1;
            else occ = 0;

            deleteChild();
            nw = ne = sw = se = NULL;
            data = occ;
            width /= w;
            return;
        }
        width /= w;

        if(nw != NULL){
            nw->Rutil2(m-1, w, d);
            ne->Rutil2(m-1, w, d);
            sw->Rutil2(m-1, w, d);
            se->Rutil2(m-1, w, d);
        }
        return;
    }

    void refresh(){
        if(nw == NULL) return;

        nw->refresh();
        ne->refresh();
        sw->refresh();
        se->refresh();

        if((nw->nw == NULL && ne->nw == NULL) && (se->nw == NULL && sw->nw == NULL)){
            if(allEqual(nw->data, ne->data, se->data, sw->data)){
                data = nw->data;
                deleteChild();
                nw = ne = sw = se = NULL;
            }
        }
        return;
    }

    quad_tree* extractUtil(quad_tree &r, long long _x, long long _y, long long m, long long w){
        // If leaf
        // cout << ++cnt << " " << _x << " " << _y << " " << m << " " << n << " " << x << " " << y << " " << endl;
        // return new quad_tree(0, 0, _x, _y);
        if(m==0){
            return new quad_tree(0, r.get(_x, _y), _x, _y);
        }

        long long Xc = _x+width/2;
        long long Yc = _y+width/2;

        // cout << "test" << endl;

        // If completely inside the tree
        if(nw == NULL){
            return new quad_tree(m, data, _x, _y);
        }

        // cout << "\tfuck" << endl;
        if(_x+w/2 < Xc && _y+w/2 < Yc)
            return nw->extractUtil(r, _x, _y, m, w);

        if(Xc <= _x && _y+w/2 < Yc)
            return ne->extractUtil(r, _x, _y, m, w);

        if(_x+w/2 < Xc && Yc <= _y)
            return sw->extractUtil(r, _x, _y, m, w);

        if(Xc <= _x && Yc <= _y)
            return se->extractUtil(r, _x, _y, m, w);
        
        
        
        // cout << "test" << endl;
        // If not completely inside
        quad_tree *temp = new quad_tree(m, 0, _x, _y);
        temp->nw = extractUtil(r, _x, _y, m-1, w/2);
        temp->ne = extractUtil(r, _x+w/2, _y, m-1, w/2);
        temp->sw = extractUtil(r, _x, _y+w/2, m-1, w/2);
        temp->se = extractUtil(r, _x+w/2, _y+w/2, m-1, w/2);

        return temp;
    }

    void fixCord(long long _x, long long _y, long long w){
        x = _x;
        y = _y;
        width = w;
        if(nw == NULL){
            return;
        }

        nw->fixCord(_x, _y, w/2);
        ne->fixCord(_x+width/2, _y, w/2);
        sw->fixCord(_x, _y+width/2, w/2);
        se->fixCord(_x+width/2, _y+width/2, w/2);
        return;
    }

public:
    quad_tree(int _n, int b=0, long long _x=0, long long _y=0){
        n = _n;
        data = b;
        width = (1<<n);
        x = _x;
        y = _y;
        nw = ne = sw = se = NULL;
    }

    quad_tree(quad_tree const &Q){
        data = Q.data;
        n = Q.n;
        width = Q.width;
        x = Q.x, y = Q.y;

        if(Q.nw != NULL) nw = new quad_tree(*(Q.nw)); else nw = NULL;
        if(Q.ne != NULL) ne = new quad_tree(*(Q.ne)); else ne = NULL;
        if(Q.sw != NULL) sw = new quad_tree(*(Q.sw)); else sw = NULL;
        if(Q.se != NULL) se = new quad_tree(*(Q.se)); else se = NULL;
    }

    ~quad_tree(){
        if(nw != NULL) delete nw;
        if(ne != NULL) delete ne;
        if(sw != NULL) delete sw;
        if(se != NULL) delete se;
    }

    quad_tree operator=(const quad_tree &q){
        if(this != &q){
            n = q.n;
            width = q.width;
            data = q.data;
            x = q.x;
            y = q.y;

            if(q.nw != NULL){
                if(nw != NULL) delete nw;
                nw = new quad_tree(*q.nw);
            }
            if(q.ne != NULL){
                if(ne != NULL) delete ne;
                ne = new quad_tree(*q.ne);
            }
            if(q.sw != NULL){
                if(sw != NULL) delete sw;
                sw = new quad_tree(*q.sw);
            }
            if(q.sw != NULL){
                if(sw != NULL) delete sw;
                sw = new quad_tree(*q.sw);
            }
        }

        return *this;
    }

    void set(long long x1, long long y1, long long x2, long long y2, int b, bool first=true){
        if(b==data && nw==NULL) return;

        if(n == 0){
            data = b;
            return;
        }

        if(nw==NULL){
            if(x==x1 && y==y1 && x2==x+width-1 && y2==y+width-1){
                data = b;
                return;
            }else{
                makeChild();
            }
        }
    
        if(x1 < x+width/2 && y1 < y+width/2)
            nw->set(x1, y1, std::min(nw->x+(int)nw->width-1, x2), std::min(nw->y+(int)nw->width-1,y2), b, false);
        
        if(x2 >= x+width/2 && y1 < y+width/2)
            ne->set(std::max(ne->x,x1), y1, x2, std::min(ne->y+(int)ne->width-1,y2), b, false);
        
        if(x1 < x+width/2 && y2 >= y+width/2)
            sw->set(x1, std::max(sw->y,y1), std::min(sw->x+(int)sw->width-1,x2), y2, b, false);
        
        if(x2 >= x+width/2 && y2 >= y+width/2)
            se->set(std::max(se->x,x1), std::max(se->y,y1), x2, y2, b, false);
        
        if(first) refresh();
        return;
    }

    int get(long long _x, long long _y){
        if(nw == NULL)
            return data;

        if(x+width/2 <= _x){
            if(y+width/2 <= _y){
                return se->get(_x,_y);
            }else{
                return ne->get(_x,_y);
            }
        }else{
            if(y+width/2 <= _y){
                return sw->get(_x,_y);
            }else{
                return nw->get(_x,_y);
            }
        }
        return data;
    }

    int size(){
        return n;
    }

    void overlap(quad_tree const &Q, bool f=true){
        if(nw == NULL){
            if(Q.nw == NULL){
                data = (data | Q.data);
                return;
            }else{
                makeChild();
            }
        }else{
            if(Q.nw == NULL){
                overlapUtil(Q.data);
                return;
            }
        }

        nw->overlap(*Q.nw,false);
        ne->overlap(*Q.ne,false);
        sw->overlap(*Q.sw,false);
        se->overlap(*Q.se,false);
        if(f) refresh();
        return;
    }

    void intersect(quad_tree const &Q, bool f = true){
        if(nw == NULL){
            if(Q.nw == NULL){
                data = (data & Q.data);
                return;
            }else{
                makeChild();
            }
        }else{
            if(Q.nw == NULL){
                intersectUtil(Q.data);
                return;
            }
        }

        nw->intersect(*Q.nw, false);
        ne->intersect(*Q.ne, false);
        sw->intersect(*Q.sw, false);
        se->intersect(*Q.se, false);
        if(f) refresh();
        return;
    }

    void complement(){
        if(nw == NULL){
            data = !data;
            return;
        }
        nw->complement();
        ne->complement();
        sw->complement();
        se->complement();
        return;
    }

    void resize(long long m){
        if(m == n) return;
        long long w;
        int d;
        if(m > n){
            d = m-n;
            w = (1<<d);
            Rutil1(m, w, d);
        }else{
            d = n-m;
            w = (1<<d);
            Rutil2(m, w, d);
        }
        refresh();
        return;
    }

    void extract(long long _x, long long _y, long long m){
        refresh();
        long long w = (1<<m);
        quad_tree* t = extractUtil(*this, _x, _y, m, w);
        n = t->n;
        data = t->data;
        x = t->x;
        y= t->y;
        width = t->width;
        deleteChild();
        if(t->nw != NULL){
            nw = t->nw;
            ne = t->ne;
            sw = t->sw;
            se = t->se;
        }else{
            nw = ne = sw = se = NULL;
        }
        t->nw = t->ne = t->se = t->sw = NULL;
        delete t;
        this->fixCord(0, 0, width);
        refresh();
        return;
    }

};
