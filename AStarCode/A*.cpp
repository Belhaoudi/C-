#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::sort;


enum class State {kEmpty, kObstacle,KClose,kPath};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else{
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  
  return board;
}

string CellString(State cell) {
  string state;
  switch(cell) {
    case State::kObstacle: state ="#   ";
    break;
    case State::kEmpty: state = "0   ";
    break;
    case State::KClose: state = "C   "; /*state = "\u0444!   "*/
    break;
    case State::kPath: state = "P   ";
    
  }
  
  return state;
}
  

void PrintBoard(const vector<vector<State>> board) {
  for(auto v :board){
    for(auto S : v ){
       cout << CellString(S);
    }
    cout << "\n";
  }
    
  
}




bool Compare(vector<int> node1 , vector<int> node2){
    int f1 = node1[2]+node1[3];
    int f2 = node2[2]+node2[3];
    if (f1>f2)
    {
        return true;
    }else
    {
        return false;
    }
      
}



void CellSort(vector<vector<int>> &openList ){

    sort(openList.begin(),openList.end(),Compare);

}


//calculat tha  Manhattan Distance from oune card to athor
int heuristic(int x1 , int x2 ,int y1, int y2){
  //that equation calculat the  Manhattan Distance (howmuch step between [x1,y1] and [x2,y2]) 
  return abs(x2-x1)+abs(y2-y1);
}


void AddToOpen(int x , int y , int g , int h , vector<vector<State>> &board , vector<vector<int>> &openList ){

  vector<int>  node{x,y,g,h};

  openList.push_back(node);
  board[x][y]=State::KClose;

}

bool CheckValidCell(int x, int y,vector<vector<State>> &board){

    State cell = State::KClose;
    if (x>=0 && y>=0 && x<=4 && y<=5)
    {
      cell = board[x][y];
    }
    
    if (cell == State::kEmpty)
    {
      return true;
    }
    return false;

}


void ExpandNeighbors(int currentNode[3],int goal[2],vector<vector<State>> &board , vector<vector<int>> &open){

      static const vector<vector<int>> clearvec;
      open = clearvec;
      
      
        if (CheckValidCell(currentNode[0]+1,currentNode[1],board)){

          //AddToOpen(currentNode[0]+1,currentNode[1],currentNode[2]+1,heuristic(currentNode[0]+1,goal[0],currentNode[1],goal[1]),board,openList);
          open.push_back({currentNode[0]+1,currentNode[1],currentNode[2]+1,heuristic(currentNode[0]+1,goal[0],currentNode[1],goal[1])});
          

        }
        if (CheckValidCell(currentNode[0],currentNode[1]+1,board)){

          //AddToOpen(currentNode[0],currentNode[1]+1,currentNode[2]+1,heuristic(currentNode[0],goal[0],currentNode[1]+1,goal[1]),board,openList);
          open.push_back({currentNode[0],currentNode[1]+1,currentNode[2]+1,heuristic(currentNode[0],goal[0],currentNode[1]+1,goal[1])});
          

         }
        if (CheckValidCell(currentNode[0]-1,currentNode[1],board)){

          //AddToOpen(currentNode[0]-1,currentNode[1],currentNode[2]+1,heuristic(currentNode[0]-1,goal[0],currentNode[1],goal[1]),board,openList);
          open.push_back({currentNode[0]-1,currentNode[1],currentNode[2]+1,heuristic(currentNode[0]-1,goal[0],currentNode[1],goal[1])});
          

         }
        if (CheckValidCell(currentNode[0],currentNode[1]-1,board)){

          //AddToOpen(currentNode[0],currentNode[1]-1,currentNode[2]+1,heuristic(currentNode[0],goal[0],currentNode[1]-1,goal[1]),board,openList);
          open.push_back({currentNode[0],currentNode[1]-1,currentNode[2]+1,heuristic(currentNode[0],goal[0],currentNode[1]-1,goal[1])});
          

         }
         
      
      
      

}


vector<vector<State>> Search(vector<vector<State>> &board , int start[2],int goal[2] , vector<vector<int>> &openList){

  vector<vector<int>> open{{0,0,0,9}};
  do
  {  
      int currentNode[3];
      do
      {
      
        bool isGoal=true;
        CellSort(open);
        if (open.size()>0)
        {
          AddToOpen(open[open.size()-1][0],open[open.size()-1][1],open[open.size()-1][2],heuristic(open[open.size()-1][0],goal[0],open[open.size()-1][1],goal[1]) , board, openList);
        }
        
          
         for(int i=0 ;i<3;i++){
            currentNode[i]=openList[openList.size()-1][i];
         }
         //currentNode[3]={openList[openList.size()-1][0],openList[openList.size()-1][1],openList[openList.size()-1][2]}; 
        board[currentNode[0]][currentNode[1]]= State::kPath;

            for(int i=0 ; i<2;i++){          
              if (currentNode[i] != goal[i])
              {
                isGoal =false;
                break;

              }
            } 

            if (isGoal)
            {
              return board;
            }

        ExpandNeighbors(currentNode,goal,board,open);

      }while (open.size()>0 );
      board[currentNode[0]][currentNode[1]]= State::KClose;
      openList.erase(openList.begin()+openList.size()-1);

  }while (openList.size()>0);
  cout << "\nno path dispo\n";
  return board;
}

int main() {
  
  vector<vector<State>> board = ReadBoardFile("./Files/board.txt");
  int start[2]{0,0},goal[2]{4,5};
  vector<vector<int>> openList;
  
  PrintBoard(Search(board,start,goal,openList));
  
}