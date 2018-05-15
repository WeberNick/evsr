//
// Created by Alexander Weiß on 27.04.18.
//

#pragma once

#include "types.hh"
#include <string>

class WordEmbeddings {
  private:
    explicit WordEmbeddings();
    WordEmbeddings(const WordEmbeddings&) = delete;
    WordEmbeddings(WordEmbeddings&&) = delete;
    WordEmbeddings& operator=(const WordEmbeddings&) = delete;
    WordEmbeddings& operator=(WordEmbeddings&&) = delete;
    ~WordEmbeddings();

  private:
    /**
     * @brief Start to read in the model file
     *
     * @param aFile the model file to read
     */
    int loadModel(const std::string& aModelFile);

  public:
    void read(const std::string& aFile);

    /**
     * @brief Get the Instance object
     *
     * @return DocumentManager&
     */
    inline static WordEmbeddings& getInstance() {
        static WordEmbeddings lInstance;
        return lInstance;
    }
    /**
     * @brief
     *
     * @param aControlBlock
     */
    void init(const control_block_t& aControlBlock, const std::string& aModelFile);

  private:
    const control_block_t* _cb;
    bool _init;

    std::string _modelFile;
};
