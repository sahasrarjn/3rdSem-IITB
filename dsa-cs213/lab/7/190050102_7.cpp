#include<bits/stdc++.h>
#include<unordered_map>
#include<sstream>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int noCourses, noStudents, maxCourses, noOperations;
    cin >> noCourses >> noStudents >> maxCourses >> noOperations;

    // Courses
    unordered_map <string, int> courseIDs;
    unordered_map <int, string> RevCourseIDs;
    vector < vector<int> > studentsInCourse(noCourses);
    vector <int> max_Student_in_Course;
    vector <int> slot_Courses;

    // Students
    unordered_map <string, int> studentIDs;
    unordered_map <int, string> RevStudentIDs;
    vector< vector<int> > coursesTaken(noStudents);
    vector < vector<bool> > slotBusy(noStudents, vector<bool>(20, false));

    string a;
    int b, c;
    int cnt=0;
    for(int i=0; i<noCourses; i++){
        cin >> a >> b >> c;
        if(c == -1) c = 1000000;
        courseIDs[a] = cnt; 
        RevCourseIDs[cnt] = a;
        cnt++;
        slot_Courses.push_back(b);
        max_Student_in_Course.push_back(c);
    }

    cnt = 0;
    for(int i=0; i<noStudents; i++){
        cin >> a;
        studentIDs[a] = cnt; 
        RevStudentIDs[cnt] = a;
        cnt++;
    }

    char p;
    string q, r;
    for(int o=0; o<noOperations; o++){
        cin >> p;
        switch(p){
            case 'R': {
                cin >> q >> r;
                if (studentIDs.find(q) == studentIDs.end()){
                    cout << "fail\n"; continue;
                }
                if (courseIDs.find(r) == courseIDs.end()){
                    cout << "fail\n"; continue;
                }

                int student = studentIDs[q];
                int course = courseIDs[r];
                
                if(studentsInCourse[course].size() >= max_Student_in_Course[course]){
                    cout << "fail\n"; continue;
                }
                if(coursesTaken[student].size() >= maxCourses){
                    cout << "fail\n"; continue;
                }

                if( find(coursesTaken[student].begin(), coursesTaken[student].end(), course) != coursesTaken[student].end()){
                    cout << "fail\n"; continue;
                }
                
                int slot = slot_Courses[course];
                if(slotBusy[student][slot]){
                    cout << "fail\n"; continue;
                }


                studentsInCourse[course].push_back(student);
                coursesTaken[student].push_back(course);
                slotBusy[student][slot] = true;
                cout << "success\n";
                break;
            }
            case 'D':{
                cin >> q >> r;
                if (studentIDs.find(q) == studentIDs.end()){
                    cout << "fail\n"; continue;
                }
                if (courseIDs.find(r) == courseIDs.end()){
                    cout << "fail\n"; continue;
                }

                int student = studentIDs[q];
                int course = courseIDs[r];

                // Heavy
                auto courseIter = find(coursesTaken[student].begin(), coursesTaken[student].end(), course);
                auto studentIter = find(studentsInCourse[course].begin(), studentsInCourse[course].end(), student);

                if( courseIter == coursesTaken[student].end()){
                    cout << "fail\n"; continue;
                }

                int slot = slot_Courses[course];

                coursesTaken[student].erase(courseIter);
                studentsInCourse[course].erase(studentIter);
                slotBusy[student][slot] = false;

                cout << "success\n";
                break;
            }
            case 'P':{
                string line;
                getline(cin, line);
                istringstream iss(line);
                iss >> q;
                bool b = bool(iss >> r);
                
                if(!b){
                    // single input
                    int inpSize = q.size();
                    if(inpSize == 9){
                        // 3. P rollno

                        vector <string> temp;
                        int student = studentIDs[q];
                        for(int j=0; j<coursesTaken[student].size(); j++){
                            temp.push_back(RevCourseIDs[coursesTaken[student][j]]);
                        }
                        sort(temp.begin(), temp.end());
                        for(int j=0; j<temp.size(); j++){
                            cout << temp[j] << " ";
                        }
                        temp.clear();
                        cout << '\n';
                    }else{
                        // 4. P course

                        vector <string> temp;
                        int course = courseIDs[q];
                        for(int j=0; j<studentsInCourse[course].size(); j++){
                            temp.push_back(RevStudentIDs[studentsInCourse[course][j]]);
                        }
                        sort(temp.begin(), temp.end());
                        for(int j=0; j<temp.size(); j++){
                            cout << temp[j] << " ";
                        }
                        temp.clear();
                        cout << '\n';
                    }

                }else{
                    // double inputs
                    int inpSize = q.size();
                    if(inpSize == 9){
                        // 5. P rollno1 rollno2

                        int student1 = studentIDs[q];
                        int student2 = studentIDs[r];

                        vector <string> temp1, temp2;
                        vector <string> intersection(maxCourses);

                        for(int j=0; j<coursesTaken[student1].size(); j++){
                            temp1.push_back(RevCourseIDs[coursesTaken[student1][j]]);
                        }
                        for(int j=0; j<coursesTaken[student2].size(); j++){
                            temp2.push_back(RevCourseIDs[coursesTaken[student2][j]]);
                        }
                        sort(temp1.begin(), temp1.end());
                        sort(temp2.begin(), temp2.end());

                        auto it=std::set_intersection (temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), intersection.begin());
                        intersection.resize(it-intersection.begin());

                        for (it=intersection.begin(); it!=intersection.end(); ++it)
                            std::cout << *it << " ";
                        std::cout << '\n';

                        intersection.clear();
                        temp1.clear();
                        temp2.clear();
                    }else{
                        // 6. P course1 course2

                        int course1 = courseIDs[q];
                        int course2 = courseIDs[r];

                        vector <string> temp1, temp2;
                        vector <string> intersection(max(max_Student_in_Course[course1], max_Student_in_Course[course2]));

                        for(int j=0; j<studentsInCourse[course1].size(); j++){
                            temp1.push_back(RevStudentIDs[studentsInCourse[course1][j]]);
                        }
                        for(int j=0; j<studentsInCourse[course2].size(); j++){
                            temp2.push_back(RevStudentIDs[studentsInCourse[course2][j]]);
                        }
                        sort(temp1.begin(), temp1.end());
                        sort(temp2.begin(), temp2.end());

                        auto it=std::set_intersection (temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), intersection.begin());
                        intersection.resize(it-intersection.begin());

                        for (it=intersection.begin(); it!=intersection.end(); ++it)
                            std::cout << *it << " ";
                        std::cout << '\n';

                        intersection.clear();
                        temp1.clear();
                        temp2.clear();
                    }
                }

                iss.clear();
                break;
            }
        }
    }
    
}