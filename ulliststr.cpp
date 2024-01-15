#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string *ULListStr::getValAtLoc(size_t loc) const {
    if(loc >= size_){
        return NULL;
    }
    int count = 0;
    Item *temp = head_;
    count += temp->last - temp->first;
    while(count <= loc){
        temp = temp->next;
        count += temp->last - temp->first;
    }
    return &(temp->val[temp->last+loc-count]);
}

void ULListStr::push_front(const std::string &val) {
    if(head_ == NULL){
        head_ = new Item();
        head_->val[0] = val;
        head_->first = 0;
        head_->last = 1;
        head_->prev = NULL;
        head_->next = NULL;
        tail_ = head_;
    } else if(head_->first > 0){
        head_->first--;
        head_->val[head_->first] = val;
    } else {
        Item *temp = new Item();
        temp->val[ARRSIZE-1] = val;
        temp->first = ARRSIZE-1;
        temp->last = ARRSIZE;
        temp->prev = NULL;
        temp->next = head_;
        head_->prev = temp;
        head_ = temp;
    }
    size_++;
}

void ULListStr::pop_front() {
    if(head_ == NULL){
        return;
    } else if(head_->last == head_->first + 1){
        if(head_->next == NULL){
            clear();
            return;
        } else {
            Item *temp = head_->next;
            delete head_;
            temp->prev = NULL;
            head_ = temp;
        }
    } else {
        head_->first++;
    }
    size_--;
}

void ULListStr::push_back(const std::string &val) {
    if(tail_ == NULL){
        head_ = new Item();
        head_->val[0] = val;
        head_->first = 0;
        head_->last = 1;
        head_->prev = NULL;
        head_->next = NULL;
        tail_ = head_;
    } else if(tail_->last < ARRSIZE){
        tail_->val[tail_->last] = val;
        tail_->last++;
    } else {
        Item *temp = new Item();
        temp->val[0] = val;
        temp->first = 0;
        temp->last = 1;
        temp->prev = tail_;
        temp->next = NULL;
        tail_->next = temp;
        tail_ = temp;
    }
    size_++;
}

void ULListStr::pop_back() {
    if(tail_ == NULL){
        return;
    } else if(tail_->last == tail_->first + 1){
        if(tail_->prev == NULL){
            clear();
            return;
        } else {
            Item *temp = tail_->prev;
            delete tail_;
            temp->next = NULL;
            tail_ = temp;
        }
    } else {
        tail_->last--;
    }
    size_--;
}

std::string const &ULListStr::back() const {
    return tail_->val[tail_->last-1];
}

std::string const &ULListStr::front() const {
    return head_->val[head_->first];
}

