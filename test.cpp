#include <iostream>
#include <vector>

using namespace std;

int main(void){

    vector<int> v;
    vector<int>::iterator it;
    v.push_back(1);

    v.push_back(2);

    v.push_back(3);

    v.push_back(4);

    v.push_back(5);
    // for(int i=0; i<v.size(); ++i){

    // }
    for (auto iter = v.begin(); iter != v.end();iter++){ 
        cout << *iter << endl;
        if (*iter == 3){
            it = iter;
            iter = v.erase(iter); 
        }
            
        // } else {

        //     iter++; 
        // }

    }


    for(const auto itr:v) { 
        cout << itr << " ";
    }
    cout << *it << " ";

    return 0;

}
