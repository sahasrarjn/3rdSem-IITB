class permutation{
    int n, *a;

public:
    // Constructors and Destructors
    // Working
    permutation(int m, int in[]){
        n = m;
        a = new int [n];
        for(int i=0; i<n; i++) a[i] = in[i];
    };

    
    // Working
    permutation(permutation const &q){
        n = q.n;
        a = new int [n];

        for(int i=0; i<n; i++){
            a[i] = q.a[i];
        }
    }

    // Not Working
    permutation const & operator=(permutation const &q){
        if(&q ==  this) return *this;
        delete []a;

        permutation ans(q);
        return q;
    }
    
    ~permutation(){
        delete []a;
    }

};