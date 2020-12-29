class quad_tree{
    int n;
    long long n2;    // 2^n * 2^n
    int *a;

public:
    quad_tree(int n, int b=0){
        this->n = n;
        n2 = (1<<n);
        n2 = n2*n2;
        a = new int[n2];
        for(long long i=0; i<n2; i++){
            a[i] = b;
        }
    }

    quad_tree(quad_tree const &Q){
        n = Q.n;
        n2 = Q.n2;
        for(long long i=0; i<n2; i++){
            a[i] = Q.a[i];
        }
    }

    ~quad_tree(){
        delete []a;
    }

    void set(int x1, int y1, int x2, int y2, int b){
        for(int i=x1; i<=x2; i++){
            long long x = i * (1<<n);
            for(int j=y1; j<=y2; j++){
                a[x+j] = b;
            }
        }
    }

    int get(int x1, int y1) const{
        long long x = x1 * (1<<n);
        return a[x+y1];
    }

    int size(){
        return n;
    }
};