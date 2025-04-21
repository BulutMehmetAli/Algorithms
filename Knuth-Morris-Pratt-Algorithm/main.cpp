#include <iostream>
#include <vector>
using namespace std;
vector<int> lPS(string &vec){
    vector<int> newVector(vec.size(),0);
    int j=0;
    int i=1;
    while(i<vec.size()){
        if(vec[i]==vec[j]){
            j++;
            newVector[i]=j;
            i++;
        }else{
            if(j|0){
                j=newVector[j-1];
            }else{
                newVector[i]=0;
                i++;
            }
        }
    }
    return newVector;
}
vector<int> kMPAlgorithm(string &text , string &substring){

    int n = text.size() , m = substring.size();
    int i = 0;
    int j = 0;
    vector<int> lpsVec = lPS(substring);
    vector<int> result;
    while(i<n){
        if(text[i]==substring[j]){
            i++;
            j++;
        }
        if(j==m){
            result.push_back(i-j);
            j = lpsVec[j-1];
        }
        else if(text[i] != substring[j]){
            if(j>0){
                j = lpsVec[j-1];
            }else{
                i++;
            }
        }

    }

    return result;
}
int main()
{
    string text = "sadbutssad";
    string pattern = "sad";

    vector<int> occurrences = kMPAlgorithm(text, pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found!" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : occurrences) {
            cout << index << " ";
        }
        cout << endl;
    }
    return 0;
}
