// https://school.programmers.co.kr/learn/courses/19344/lessons/242258
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    vector<int> arr(attacks.back()[0]);
    
    for(auto cont: attacks){
        arr[cont[0] -1] = cont[1];
    }
    
    int continuedSuccess = 0;
    int currentHealth = health;
    
    for(auto atk: arr){
        currentHealth -= atk;

        if(currentHealth <= 0){
            currentHealth = -1;
            break;
        }

        if(atk){
            continuedSuccess = 0;
            continue;
        }
        
        currentHealth += bandage[1];
        continuedSuccess++;
        
        if(continuedSuccess == bandage[0]){
            continuedSuccess = 0;
            currentHealth += bandage[2];
        }
        
        currentHealth = min(health, currentHealth);
        
    }
    
    
    return answer = currentHealth;
}
