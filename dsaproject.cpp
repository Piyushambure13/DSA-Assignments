#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define INF 9999

int mindistance(vector<int> &distance, vector<bool> &visited, int V) {
  int minimum = INT_MAX, ind = -1;
  for (int v = 0; v < V; v++) {
    if (!visited[v] && distance[v] <= minimum) {
      minimum = distance[v];
      ind = v;
    }
  }
  return ind;
}

void dijkstra(const vector<vector<int>> &graph, int source,
              vector<int> &distance, int V) {
  vector<bool> visited(V, false);
  distance[source] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = mindistance(distance, visited, V);
    visited[u] = true;

    for (int v = 0; v < V; v++) {
      if (!visited[v] && graph[u][v] && distance[u] != INF &&
          distance[u] + graph[u][v] < distance[v]) {
        distance[v] = distance[u] + graph[u][v];
      }
    }
  }
}

class Book {
private:
  int from, to, no, type;
  string ans;
  unordered_map<string, int> station_map;
  vector<string> stations;
  vector<vector<int>> graph;
  void initialize();

public:
  Book() { initialize(); }
  void menu();
  void booking();
  void timetable();
  void station();
  void contact_us();
  void Credit();
};

void Book::initialize() {

  stations = {"Ramwadi",
              "Kalyani Nagar",
              "Yerwada",
              "Bund Garden",
              "Ruby Hall Clinic",
              "Pune Railway Station",
              "Mangalwar Peth",
              "Civil Court",
              "PMC",
              "Chh. Sambhaji Udyan",
              "Deccan Gym",
              "Garware College",
              "Ideal Colony",
              "Vanaz"};

  for (int i = 0; i < stations.size(); i++) {
    station_map[stations[i]] = i;
  }

  graph = {{0, 10, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
           {10, 0, 8, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
           {INF, 8, 0, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
           {INF, INF, 5, 0, 12, INF, INF, INF, INF, INF, INF, INF, INF, INF},
           {INF, INF, INF, 12, 0, 4, INF, INF, INF, INF, INF, INF, INF, INF},
           {INF, INF, INF, INF, 4, 0, 3, INF, INF, INF, INF, INF, INF, INF},
           {INF, INF, INF, INF, INF, 3, 0, 6, INF, INF, INF, INF, INF, INF},
           {INF, INF, INF, INF, INF, INF, 6, 0, 7, INF, INF, INF, INF, INF},
           {INF, INF, INF, INF, INF, INF, INF, 7, 0, 3, INF, INF, INF, INF},
           {INF, INF, INF, INF, INF, INF, INF, INF, 3, 0, 2, INF, INF, INF},
           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, 0, 3, INF, INF},
           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, 0, 5, INF},
           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 0, 3},
           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, 0}};
}

void Book::menu() {
  int choice;
  cout << "\n\n\n\t\t\t______________________________________________HOME______"
          "________________________________________________";
  cout << "\n\t\t\t1.Booking\n\t\t\t2.Timetable\n\t\t\t3.Stations\n\t\t\t4."
          "Contact Us\n\t\t\t5.Exit\n\t\t\t6.Credit\n";
  cout << "Choose an Operation: ";
  cin >> choice;

  switch (choice) {
  case 1:
    booking();
    break;
  case 2:
    timetable();
    break;
  case 3:
    station();
    break;
  case 4:
    contact_us();
    break;
  case 5:
    cout << "Thanks for visiting!\n";
    break;
  case 6:
    Credit();
    break;
  default:
    cout << "Invalid choice. Please try again.\n";
    menu();
  }
}

void Book::station() {
  cout << "\nAvailable Stations:\n";
  for (const auto &station : stations) {
    cout << station << endl;
  }

  cout << "\nDo you want to go to the home menu (YES/yes): ";
  cin >> ans;
  if (ans == "YES" || ans == "yes")
    menu();
}

void Book::timetable() {
  cout << "Timetable:\n";
  cout << "Service Time: 7 AM to 11 PM\n";
  cout << "Train Frequency in peak hours: 10 mins\n";
  cout << "Train Frequency in non-peak hours: 10 mins\n";
  cout << "Total journey time from Ramwadi to Vanaz: 40min\n";

  cout << "Station Stopping Time: 30 Sec\n";

  cout << "\nDo you want to go to the home menu (YES/yes): ";
  cin >> ans;
  if (ans == "YES" || ans == "yes")
    menu();
}

void Book::booking() {
  string from_station, to_station;
  cout << "1.Ramwadi" << endl;
  cout << "2.Kalyani nagar" << endl;
  cout << "3.Yerwada" << endl;
  cout << "4.Bund garden" << endl;
  cout << "5.Ruby hall clinic" << endl;
  cout << "6.Pune railway st." << endl;
  cout << "7.Mangalwar peth" << endl;
  cout << "8.Civil court" << endl;
  cout << "9.PMC" << endl;
  cout << "10.Chh. Sambhaji Udyan" << endl;
  cout << "11.Deccan gym" << endl;
  cout << "12.Garware clg" << endl;
  cout << "13.Ideal colony" << endl;
  cout << "14.Vanaz" << endl;
  cout << "\nEnter your starting station: ";
  cin >> from_station;
  cout << "Enter your destination station: ";
  cin >> to_station;

  if (station_map.find(from_station) == station_map.end() ||
      station_map.find(to_station) == station_map.end()) {
    cout << "Invalid station entered!\n";
    return;
  }

  from = station_map[from_station];
  to = station_map[to_station];

  vector<int> distance(stations.size(), INF);
  dijkstra(graph, from, distance, stations.size());

  cout << "Minimum distance from " << from_station << " to " << to_station
       << " is: " << (distance[to] / 10) << " Kms\n";

  cout << " Number of Tickets: ";
  cin >> no;
  cout << " Journey type: \n1. One Way\n2. Return\n";
  cin >> type;

  float fare = distance[to] * 1 * no * (type == 1 ? 1 : 2);
  cout << " Fare: " << fare << " Rs.\n";
  cout << " Time required for journey : " << (distance[to] * 2) / 10
       << " mins\n";
  cout << " ***************************************  THANK YOU  "
          "*****************************************\n";
}

void Book::contact_us() {
  cout << "Contact Us:\n";
  cout << "Phone: 1800-123-456\n";
  cout << "Email: Pune_metro@support.com\n";

  cout << "\nDo you want to go to the home menu (YES/yes): ";
  cin >> ans;
  if (ans == "YES" || ans == "yes")
    menu();
}

void Book::Credit() {
  cout << "Developed by: \n";
  cout << "\n\t\t\t1. SUJAL KARNAWAT (23533)\n\t\t\t2. PIYUSH AMBURE "
          "(23502)\n\t\t\t3. ISHWARI JEUGHALE (23527)\n\t\t\t4. YASH GIRGUNE "
          "(23522)\n";
}

int main() {
  Book metro;
  cout << "Welcome to Metro Ticket Booking System\n";
  metro.menu();
  return 0;
}
