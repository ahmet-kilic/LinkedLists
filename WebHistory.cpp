#include "WebHistory.hpp"

WebHistory::WebHistory()
{
    // Does nothing.
}

WebHistory::WebHistory(std::string historyText)
{
	// history = url timestamp | url timestamp | url timestamp...
    // urls are string and timestamps are non-negative integers.
    std::string delimiter = " | ";

	std::string tabInfo;
    std::string url;
    std::string timestamp;
    size_t pos = 0;

    while (true)
	{
        pos = historyText.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        tabInfo = historyText.substr(0, pos);
        historyText.erase(0, pos + delimiter.length());

        pos = tabInfo.find(" ");

        url = tabInfo.substr(0, pos);
        timestamp = tabInfo.substr(pos + 1, tabInfo.length() - pos);

		Node<Tab> *newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
        insertInOrder(newPage);

        if (breakTheLoop)
		{
			break;
		}
    }
}

void WebHistory::printHistory()
{
	std::cout << "Your web history:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
	if (history.getHead()->next == history.getTail())
	{
		std::cout << "History is empty." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		Node<Tab> *node = history.getFirstNode();

		while (node != history.getTail())
		{
		    std::cout << "Page: " << node->element.getUrl() << std::endl;
			std::cout << "Last Visited: " << node->element.getTimestamp() << std::endl;
			std::cout << std::endl;
		    node = node->next;
		}
	}
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

WebHistory::WebHistory(std::string url, int timestamp)
{
	// TODO
  Tab newtab(url, timestamp);
  history.insertAtTheEnd(newtab);
}

WebHistory::~WebHistory()
{
	// TODO
}

void WebHistory::insertInOrder(Node<Tab> *newPage)
{
	// TODO
  if(history.isEmpty()){
    newPage->prev = history.getHead();
    newPage->next = history.getTail();
    history.getHead()->next = newPage;
    history.getTail()->prev = newPage;
  }
  else{
    Node<Tab> *current = history.getHead()->next;
    while(current != history.getTail()){
      if(current->element <= newPage->element){
        current->prev->next = newPage;
        newPage->prev = current->prev;
        newPage->next = current;
        current->prev = newPage;
        break;
      }
      current = current->next;
    }
    if(current == history.getTail()){
      current->prev->next = newPage;
      newPage->next = current;
      newPage->prev = current->prev;
      current->prev = newPage;
    }
  }
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
  Tab newt(url, timestamp);
  Node<Tab> *newpage = new Node<Tab>;
  newpage->element = newt;
  insertInOrder(newpage);
}

void WebHistory::clearHistory()
{
	// TODO
  history.removeAllNodes();
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
  Node<Tab> *current = history.getHead()->next;
  if(history.isEmpty()) return;
  while(current != history.getTail()){
    if(current->element.getTimestamp() <= timestamp) break;
    current = current->next;
  }
  Node<Tab> *next;
  while(current != history.getTail()){
    next = current->next;
    delete current;
    current = next;
  }

}

WebHistory WebHistory::operator+(const WebHistory &rhs) const
{
	// TODO
  WebHistory newhistory;
  newhistory.history = this->history;
  Node<Tab> *current = rhs.history.getHead()->next;
  while(current != rhs.history.getTail()){
    newhistory.goToPage(current->element.getUrl(),current->element.getTimestamp());
    current = current->next;
  }
  return newhistory;
}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
  int i = 0;
  Node<Tab> *current = history.getHead()->next;
  while(current != history.getTail()){
    if(current->element.getWebSite() == pageName) i++;
    current = current->next;
  }
  return i;

}

std::string WebHistory::mostVisited()
{
	// BONUS
  int previous_count = 0;
  std::string previous_link = "";
  Node<Tab> *current = history.getFirstNode();
  while(current != history.getTail()){
     if (previous_count <= timesVisited(current->element.getWebSite())){
       previous_count = timesVisited(current->element.getWebSite());
       previous_link = current->element.getWebSite();
     }
     current = current->next;
  }
  return previous_link;
}
