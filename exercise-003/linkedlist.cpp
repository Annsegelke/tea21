#include "linkedlist.h"

LinkedList::~LinkedList()
{
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext /* prepare the next in the row */) {
    auto elem = tmp; /* save the element to be deleted */
    delete elem;
  }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  // insert your code here....
    if (nullptr == m_head) {
        m_head = node;
    } else {
        LinkedListNode *tmp = m_head;
        while (tmp->pNext != nullptr) {
            tmp = tmp->pNext;
        }
        tmp->pNext = node;
    }


  return true;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  // insert your code here....
    if (nullptr == m_head) {
        m_head = node;
    } else {
        node->pNext = m_head;
        m_head = node;
    }

  return true;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  // insert your code here ....
    node->pNext = loc->pNext;
    loc->pNext = node;

  return true;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  // Insert your code here....
     if (loc == m_head) {
        node->pNext = m_head;
        m_head = node;
    } else {
        LinkedListNode *tmp = m_head;
        while (tmp->pNext != loc) {
            tmp = tmp->pNext;
        }
        tmp->pNext = node;
        node->pNext = loc;
    }

    return true;
}


bool LinkedList::remove(LinkedListNode *node)
{
  bool ret = false;
  // insert your code here ...
    if (nullptr == node || nullptr == m_head) {
        return false;
    }

    if (m_head == node) {
        m_head = node->pNext;
        delete node;
        return true;
    }

    LinkedListNode *tmp = m_head;
    while (tmp->pNext != nullptr && tmp->pNext != node) {
        tmp = tmp->pNext;
    }

    if (tmp->pNext == nullptr) {
        return false; // Node not found
    }

    tmp->pNext = node->pNext;
    delete node;

    return true;
}


size_t LinkedList::size()
{
  size_t count = 0;
  /* using a lambda to count objects in the list*/
  traverse([&count](LinkedListNode *node) { count++; });
  return count;
}


void LinkedList::traverse(std::function<void(const std::string &)> func)
{
  traverse([&](LinkedListNode *node) { func(node->m_name); });
}

void LinkedList::traverse(std::function<void(LinkedListNode *node)> func)
{
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext) {
    func(tmp);
  }
}