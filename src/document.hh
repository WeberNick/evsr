#pragma once

#include "infra/types.hh"

#include <string>

class Document
{
    public:
        explicit Document() = delete;
        explicit Document(const size_t aDocID, const std::string& aPath);
        Document(const Document&) = delete;
        Document(Document&&) = delete;
        Document& operator=(const Document&) = delete;
        Document& operator=(Document&&) = delete;
        ~Document();
    
    public:
        //todo: helper functions to read document content into memory
        //todo: helper function to process content of a document

    public:
        //getter
        inline size_t       getID(){ return _ID; }
        inline std::string  getPath(){ return _path; }
        //setter, if needed

    private:
       size_t       _ID;
       std::string  _path;
};