#include "word_embeddings.hh"

/**
 * @brief Construct a new WordEmbeddingsManager object
 *
 */
WordEmbeddings::WordEmbeddings() :
    _cb(nullptr), _init(false), _modelFile() // relative path from /path/to/repo/vector-space-retrieval
{}

/**
 * @brief Destroy the  WordEmbeddingsManager object
 *
 */
WordEmbeddings::~WordEmbeddings() {
  delete _wordEmbeddings;
}



void WordEmbeddings::init(const control_block_t& aControlBlock) {
    if (!_init) {
        _cb = &aControlBlock;
        _modelFile = _cb->wordEmbeddingsFile();
        read(_modelFile);
        _init = true;
    }
}

void WordEmbeddings::read(const std::string &aFile) {
    std::ifstream file(aFile);
    std::string line;
    while (std::getline(file, line)) {
        string_vt parts;
        float_vt embedding;
        Utility::StringOp::splitStringBoost(line, ' ', parts);
        std::string word = parts[0];
        for (size_t j = 1; j < parts.size(); ++j) {
            embedding.push_back(stof(parts[j]));

        }
        this->insert(std::make_pair(word, embedding));
    }

}

bool WordEmbeddings::insert(const word_embedding_map_elem_t& aElement) { return (*_wordEmbeddings).insert(aElement).second; }

float_vt& WordEmbeddings::getWordEmbeddings(std::string &word) {
  if ((*_wordEmbeddings).find(word) != (*_wordEmbeddings).end())
    return (*_wordEmbeddings).at(word);
  else
    throw InvalidArgumentException(__FILE__, __LINE__, __PRETTY_FUNCTION__, "This term does not appear in the word embeddings collection.");
}
