#pragma once

#include "types.hh"
#include "exception.hh"
#include "document.hh"
#include "index_manager.hh"

#include <map>
#include <string>

class DocumentManager {
  public:
    explicit DocumentManager(const std::string& aPath);
    explicit DocumentManager() = delete;
    DocumentManager(const DocumentManager&) = delete;
    DocumentManager(DocumentManager&&) = delete;
    DocumentManager& operator=(const DocumentManager&) = delete;
    DocumentManager& operator=(DocumentManager&&) = delete;
    ~DocumentManager();

  public:
    static void createInstance(const std::string& aPath);
    static void destroyInstance();
    static DocumentManager& getInstance();

  private:
    /* start the scan for files at the root directory and add all found docs to map */
    void read(const std::string& aFile);

  public:  /* Wrapper functions for the respective map container calls */
    /* insert element into manager (by std::pair element) */
    bool insert(const doc_map_elem_t& aElement);
    /* insert element into manager (by values) */
    bool insert(const size_t aKey, const Document& aDocument);
    /* find element in manager */
    doc_map_iter_t find(const size_t aKey);
    /* erase by key */
    bool erase(const size_t aKey);
    /* erase by iterator */
    bool erase(const doc_map_iter_t aIterator);

  public:
    inline const doc_mt& getDocumentMap() { return _docs; }
    inline size_t getNoDocuments() { return _docs.size(); }
    inline size_t getCurrID(){ return _countID; }
    // setter, if needed
  
  private:
    static DocumentManager* _instance;
    static bool _isCreated;
    static size_t _countID;
    static std::string _collectionFile;

    doc_mt          _docs;
    IndexManager    _indexMgr;
};
