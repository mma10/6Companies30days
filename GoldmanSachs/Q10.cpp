// Use min priority queue (or heaps)
// Assume hyphtothetical vector acting as stream here


// Here k = 10
vector <int> findKMax(vector <int> arr,int k){
    int n = arr.size();
    priority_queue <int,vector<int>,greater<int>> topK;
    for(int i = 0; i < k; i++)
        topK.push(nums[i]);
    
    for(int i = k; i < n; i++){
        if(arr[i] > topK.top()){
            topK.pop();
            topK.push(arr[i]);
        }
    }
    vector <int> topKEle;
    while(!topK.empty()){
        topKEle.push_back(topK.top());
        topK.pop();
    }
    return topKEle;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
        
    vector <int> topK = findKMax(arr,k);
    for(int num : topK)
        cout << num << " ";
    cout << endl;    
    return 0;
}