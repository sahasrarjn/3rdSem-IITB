class permutation{
    int n, *a;

public:
    // Constructors and Destructors
    permutation(int m, int in[]){
        n = m;
        a = new int [n];
        for(int i=0; i<n; i++) a[i] = in[i];
    };

    permutation(permutation const &q){
        n = q.n;
        a = new int [n];
        for(int i=0; i<n; i++){
            a[i] = q.a[i];
        }
    }

    permutation const & operator=(permutation const &q){
        if(&q ==  this) return *this;
        delete []a;
        permutation ans(q);
        return q;
    }
    
    ~permutation(){
        delete []a;
    }

    // Public functions
    
    int size() const{
        int size = n;
        return size;
    }

    int* to_array() const{
        int *q = new int[n];
        for(int i=0; i<n; i++){
            q[i] = a[i];
        }
        return q;
    }

    permutation const operator-() const{
        permutation *q = new permutation(*this);
        q->n = n;
        for(int i=0; i<n; i++) q->a[a[i]] = i;
        return *q;
    }

    permutation const operator*(permutation const &in) const{
        int *arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = a[in.a[i]];
        permutation *temp = new permutation(n, arr);
        return *temp;
    }
};