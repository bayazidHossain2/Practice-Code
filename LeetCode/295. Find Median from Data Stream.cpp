class MedianFinder {
    private:
    multiset<int> mset;
    multiset<int>::iterator it;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if(mset.size()==0){
            mset.insert(num);
            it=mset.begin();
        }else{
            mset.insert(num);
            if(num==*it){

            }
            if(mset.size()&1){
                it++;
            }
            if(num<*it){
                it--;
            }
        }cout<<num<<" iterator is : "<<*it<<endl;
    }

    double findMedian() {
        if(mset.size()&1){
            return *it;
        }else{
            multiset<int>::iterator tit=it;
            tit++;
            cout<<*it<<' '<<*tit<<" REsult : "<<(*it+*tit+0.0)/2.0<<endl;
            return (*it+*tit+0.0)/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
