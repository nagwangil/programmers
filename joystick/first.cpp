#include <string>
#include <vector>
#include <map>

using namespace std;
map<char, int> dic{
    {'A', 0},
    {'B', 1},
    {'C', 2},
    {'D', 3},
    {'E', 4},
    {'F', 5},
    {'G', 6},
    {'H', 7},
    {'I', 8},
    {'J', 9},
    {'K', 10},
    {'L', 11},
    {'M', 12},
    {'N', 13},
    {'O', 12},
    {'P', 11},
    {'Q', 10},
    {'R', 9},
    {'S', 8},
    {'T', 7},
    {'U', 6},
    {'V', 5},
    {'W', 4},
    {'X', 3},
    {'Y', 2},
    {'Z', 1},
};

int solution(string name)
{

    int answer = -1;
    int max_continue_a = 0;
    int temp_continue_a = 0;
    for (auto alphabet : name)
    {
        if (alphabet == 'A')
        {
            temp_continue_a++;
        }
        else if (max_continue_a < temp_continue_a)
        {
            max_continue_a = temp_continue_a;
            temp_continue_a = 0;
        }
        answer += dic[alphabet] + 1;
    }

    return answer - max_continue_a;
}

int main()
{

    printf("%d\n", solution("JEROEN"));
    return 0;
}