#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> temp_numbers;

    for (auto num : numbers)
    {
        temp_numbers.push_back(to_string(num));
    }
    sort(temp_numbers.begin(), temp_numbers.end());

    for (auto num : temp_numbers)
    {
        printf("%s ", num.c_str());
    }
    printf("\n");

    for (int i = temp_numbers.size() - 1; i >= 0;)
    {
        int count = 0;
        while (true)
        {
            if (i - count == 0)
                break;

            if (temp_numbers[i - count].find(temp_numbers[i - count - 1]) != string::npos)
            {
                if (temp_numbers[i - count - 1] == "0")
                    break;

                printf("%s found substring  %s\n\r", temp_numbers[i - count].c_str(), temp_numbers[i - count - 1].c_str());
                count++;
            }
            else
            {
                break;
            }
        }

        printf("push %s \n", temp_numbers[i - count].c_str());
        answer += temp_numbers[i - count];
        temp_numbers.erase(temp_numbers.begin() + i - count);

        i--;
    }

    return answer;
}

int main()
{
    vector<int> numbers = {0, 3, 30, 34, 5, 50, 500, 9};
    vector<int> numbers1 = {0, 6, 10, 2134, 213};
    printf("%s\n", solution(numbers1).c_str());

    return 0;
}