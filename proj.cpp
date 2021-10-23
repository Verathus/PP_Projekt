#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

/**
 * @brief Struktura obiektu bazowego
 * 
 */
class Pojazd
{
public:
  std::string numerRej;
  std::string nazwa;
  int rok;
  Pojazd *next;
};

// This function prints contents of linked list starting from
// the given node
void printList(Pojazd *n)
{
  while (n != NULL)
  {
    std::cout << n->numerRej << " " << n->nazwa << " " << n->rok << std::endl;
    n = n->next;
  }
}

/**
 * @brief list all files in directory
 *  entry.path() returns a path of file -> then we get only the filename with filename() -> it will return filename with quotes "" so we remove those with .string()
 */
void listFiles(std::string path)
{
  for (const auto &entry : fs::directory_iterator(path))
  {
    std::string line;
    std::ifstream myfile(entry.path()); //"pojazdy/" + entry.path().filename().string());
    if (myfile.is_open())
    {
      while (getline(myfile, line))
      {
        std::cout << line << '\n';
      }
      myfile.close();
    }

    else
      std::cout << "Unable to open file";
  }
}

int main()
{
  Pojazd *head = NULL;
  Pojazd *second = NULL;
  Pojazd *third = NULL;
  head = new Pojazd();
  second = new Pojazd();
  third = new Pojazd();
  head->numerRej = "ABC-123";
  head->nazwa = "BMW";
  head->rok = 2010;
  head->next = second;
  second->numerRej = "XYZ-456";
  second->nazwa = "Audi";
  second->rok = 2012;
  second->next = third;
  third->numerRej = "PQR-789";
  third->nazwa = "Mercedes";
  third->rok = 2015;
  third->next = NULL;
  //head->next = second; // Link first node with second

  printList(head);
  while (head != NULL)
  {
    Pojazd *temp = head;
    std::ofstream plik;
    plik.open("pojazdy/" + head->numerRej + ".txt");
    plik << head->numerRej << " " << head->nazwa << " " << head->rok << std::endl;
    head = head->next;
  }

  listFiles("pojazdy/");

  return 0;
}