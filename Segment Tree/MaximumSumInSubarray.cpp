Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2



/********************************************** SOLUTION ***************************************************/


#include<bits/stdc++.h>
using namespace std;

struct node
{
    int maxSum;
    int sum;
    int best_pref_sum;
    int best_suf_sum;
};

void buildTree(int *arr,node *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].sum = arr[start];
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].best_pref_sum = arr[start];
        tree[treeNode].best_suf_sum = arr[start];

        return;
    }
    int mid = (start + end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode + 1);

    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];

    tree[treeNode].maxSum = max(left.maxSum,max(right.maxSum,max(left.sum + right.best_pref_sum,max(right.sum + left.best_suf_sum,left.best_suf_sum + right.best_pref_sum)))); 
    tree[treeNode].sum = left.sum + right.sum;
    tree[treeNode].best_pref_sum = max(left.sum + right.best_pref_sum,left.best_pref_sum);
    tree[treeNode].best_suf_sum = max(right.best_suf_sum,left.best_suf_sum+ right.sum);
    return;
}

node query(int *arr,node *tree,int start,int end,int treeNode,int left,int right)
{
    if(start > right || end < left)
    {
        node zero = {-100000,-100000,-100000,-100000};
        return zero;
    }
    if(start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end)/2;

    node q1 = query(arr,tree,start,mid,2*treeNode,left,right);
    node q2 = query(arr,tree,mid + 1,end,2*treeNode + 1,left,right);
    node q3; 
    q3.maxSum = max(q1.maxSum,max(q2.maxSum,max(q1.sum + q2.best_pref_sum,max(q2.sum + q1.best_suf_sum,q1.best_suf_sum + q2.best_pref_sum))));
    q3.sum = q1.sum + q2.sum;
    q3.best_pref_sum = max(q1.sum+q2.best_pref_sum,q1.best_pref_sum);
    q3.best_suf_sum = max(q1.best_suf_sum+q2.sum,q2.best_suf_sum);

    return q3;
}

void printTree(node *tree,int n)
{
    cout<<endl;
    for(int i = 0; i < 3*n; i++)
    {
        cout<<tree[i].maxSum<<" , "<<tree[i].sum <<" " <<tree[i].best_pref_sum<<" " <<tree[i].best_suf_sum<<endl;
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    int *arr = new int[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    node *tree = new node[4*n];

    buildTree(arr,tree,1,n,1);
    // printTree(tree,n);

    int q;
    cin >> q;

    while(q--)
    {
        int b,c;
        cin >> b >> c;
        node ans = query(arr,tree,1,n,1,b,c);
        cout<<ans.maxSum<<endl;
    }

    return 0;
}
