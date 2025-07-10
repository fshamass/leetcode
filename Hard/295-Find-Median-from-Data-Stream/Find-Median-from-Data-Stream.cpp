class MedianFinder {
    // Median for pre-defined sorted array, is either middle element if array size is odd,
    // or the average of 2 middle elements if array size is even ((array_size/2)-1, array_size/2)
    // To implement this with dynamic array (finding median on fly) we need to have 2 priority queues 
    // to simulate min and max heaps
    // We will always assume the top of max heap to be the middle element (or one of the middle elements)
    // and we will push the new element that is less than or equal to top of max heap to max heap. Otherwise, we will
    // push the new element to min heap.
    // However, for our assumption to always hold true, we need to balance the heaps with every new received element
    // why we balance heaps?, if our assumption that top of max heap is the middle element of all received elements
    // then size of max heap should be either equal to size of min heap if total received numbers is even or size of 
    // max heap should be larger than min heap by one element 
    // (reason is we are pushing all elements less or equal to top of max heap to max heap and total number of element is odd).
    // Think of it as if you have a vector of 5 sorted elements. The middle element (3dr element) is what we will have on top
    // of max heap. If we push all elements less than or equal to middle element to sat left container and rest to right
    // container, we will end up with left container having 3 elements and right right container having 2 elements.
    // If the above condition (max heap size should be either equal or heigher than min heap size by one) is not true, 
    // then our assumption that middle element is current top of max heap is wrong
    // if size of max heap is higher than size of min heap, that mean the current top element of max heap is to the right
    // of middle element (hence most elements went to max heap), so we move elements from max heap to min heap to satisfy 
    // heaps size conditions. on the other hand, if max heap size is less than min heap size, that means the current top
    // element of max heap is more to left of middle number hence most elements went to min heap. so we move elements from
    // min to max heap to satisfy heap size condition
    // Now we can correctly return median or middle element(s) at any time. Since we are pushing all elements that are greater
    // than current top of max heap to min heap, that means the top of min heap is the lowest element that is higher than
    // top of max heap. In other words that would be the next element of current top of max heap. 
    // so now we have all we need to find the median element"
    // if sizes of heaps are equal that means we have an even total number of elements so we will average top of min and max heap. 
    // otherwise, we have an odd number of element and current top of max heap is the middle element
    
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        if((maxH.empty()) || (num <= maxH.top())) maxH.push(num);
        else minH.push(num);
        if(maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        }else if(maxH.size() < minH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        double res = 0.0;
        if(maxH.size() == minH.size()) {
            res =  static_cast<double>(maxH.top()+minH.top())/2;
        }else {
            res = maxH.top();
        }  
        return res;      
    }
private:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */