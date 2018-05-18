/*********************************************************************
 * @file    vec_util.hh
 * @author 	Nick Weber
 * @date    Mai 18, 2018
 * @brief 	
 * @bugs 	TBD
 * @todos 	TBD
 * 
 * @section	DESCRIPTION
 * TBD
 * 
 * @section USE
 * TBD
 ********************************************************************/
#pragma once

#include "types.hh"
#include "exception.hh"
#include "trace.hh"

#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <functional>

namespace Util
{
    /**
     * @brief Create a vector consisting of the set difference of two vectors
     * @param v1 the first vector
     * @param v2 the second vector
     * @return a vector containing the set difference of both input vectors
     * @todo implement function as template for generic vector types if needed
     */
    sizet_vt difference(const sizet_vt& v1, const sizet_vt& v2);
    //template<typename T> std::vector<T> difference(std::vector<T>& v1, std::vector<T>& v2);
    
    /**
     * @brief Create a vector consisting of the set intersection of two vectors
     * @param v1 the first vector
     * @param v2 the second vector
     * @return a vector containing the set intersection of both input vectors
     * @todo implement function as template for generic vector types if needed
     */
    sizet_vt intersection(const sizet_vt& v1, const sizet_vt& v2);
    //template<typename T> std::vector<T> intersection(std::vector<T>& v1, std::vector<T>& v2);

    /**
     * @brief Calculate the number of different elements in both input vectors 
     * @param v1 the first vector
     * @param v2 the second vector
     * @return the number of different elements 
     * @todo implement function as template for generic vector types if needed
     */
    size_t numberOfDifferences(const sizet_vt& v1, const sizet_vt& v2);
    //template<typename T> size_t numberOfDifferences(std::vector<T>& v1, std::vector<T>& v2);

    /**
     * @brief Calculate the number of equal elements in both input vectors 
     * @param v1 the first vector
     * @param v2 the second vector
     * @return the number of equal elements 
     * @todo implement function as template for generic vector types if needed
     */
    size_t numberOfIntersections(const sizet_vt& v1, const sizet_vt& v2);
    //template<typename T> size_t numberOfIntersections(std::vector<T>& v1, std::vector<T>& v2);

    /**
     * @brief Generates a random normal distributed double number based on the Box muller method
     * @see https://stackoverflow.com/a/28551411
     * @param mean
     * @param stddev
     * @return normal distributed random value
     */
    double rand_normal(double mean, double stddev);

    /**
     * @brief Generates a random vector of floats with the given dimension and number in the range of min - max. Primarily used for testing
     *
     * @param dimension dimension of the created vector
     * @param min minimum number value
     * @param max maximum number value
     * @return
     */
     float_vt generateRandomVector(size_t dimension, int min, int max);

    /**
     * @brief Generates a random vector of size \dimension with random standard normal distributed values
     *
     * @param dimension
     * @return
     */
    float_vt generateRandomVectorN(size_t dimension);

    /**
     * @brief Calculates the dot product of two vectors
     *
     * @param a
     * @param b
     * @return
     */
    template <typename T>
    inline double scalar_product(std::vector<T> const& a, std::vector<T> const& b) {
        if (a.size() != b.size())
        {
                const std::string traceMsg = "Vectors do not have the same size";
                TRACE(traceMsg);
                throw VectorException(FLF, traceMsg);
        }
        return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    }

    bool randomProjectionHash(float_vt& origVec, float_vt& randVec);
}