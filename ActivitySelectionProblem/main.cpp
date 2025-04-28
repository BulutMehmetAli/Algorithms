#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}
void greedyActivitySelection(vector<Activity>& activities) {

    //Küçükten büyüğe doğru sıralandı.
    sort(activities.begin(), activities.end(), compare);
    vector<Activity*> selectedActivities;
    int n = activities.size();
    selectedActivities.push_back(&activities[0]);
    Activity *selected = &activities[0];
    for (int i = 1; i < n; i++) {
        Activity *current = &activities[i];
        if (current->start > selected->finish) {
            selectedActivities.push_back(current);
            selected = current;
        }
    }
    cout << "Selected activities:" << endl;
    for (Activity *act : selectedActivities) {
        cout << "(" << act->start << ", " << act->finish << ")" << endl;
    }

}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    greedyActivitySelection(activities);


    return 0;
}
