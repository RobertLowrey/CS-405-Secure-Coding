// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    
    ASSERT_TRUE(collection->empty()); //test to see if the collection is empty

    // if empty, the size must be 0

    ASSERT_EQ(collection->size(), 0); //testing collection size that must be 0


    add_entries(1);

    // is the collection still empty?
    
    ASSERT_FALSE(collection->empty()); //testing if the collection is still empty


    // if not empty, what must the size be?

    ASSERT_EQ(collection->size(), 1); //size must be 1 if the collection is not empty, and one entry was added
}

TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // is the collection empty?

    ASSERT_TRUE(collection->empty()); //collection should still be empty

    // if empty, the size must be 0

    ASSERT_EQ(collection->size(), 0); //collection must be 0 intially


    add_entries(5);

    // is the collection still empty?

    ASSERT_FALSE(collection->empty()); //Collection should no longer be empty


    // if not empty, what must the size be?

    ASSERT_EQ(collection->size(), 5); //size must be 5 if the collection is not empty anymore, and five entries were added

}

//Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, MaxGreaterThanOrEqual) {

    add_entries(15); //adds 15 entries to collection
    EXPECT_GE(collection->max_size(), 0); //verifies that collection -> max_size is greater than or equal to 0
    EXPECT_GE(collection->max_size(), 1); //verifies that collection -> max_size is greater than or equal to 1
    EXPECT_GE(collection->max_size(), 5); //verifies that collection -> max_size is greater than or equal to 5
    EXPECT_GE(collection->max_size(), 10); //verifies that collection -> max_size is greater than or equal to 10
    
}


//Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, CapacityGreaterThanOrEqual) {

    add_entries(15); //adds 15 entries to collection
    EXPECT_GE(collection->capacity(), 0); //verifies that collection -> capacity is greater than or equal to 0
    EXPECT_GE(collection->capacity(), 1); //verifies that collection -> capacity is greater than or equal to 1
    EXPECT_GE(collection->capacity(), 5); //verifies that collection -> capacity is greater than or equal to 5
    EXPECT_GE(collection->capacity(), 10); //verifies that collection -> capacity is greater than or equal to 10

}


//Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizingIncreasesCollection) {

    add_entries(5); //adds 5 entries to the collection
    int prevCollection = collection->size(); //creating a temp holder for collection called prevCollection
    collection->resize(20); //resizeing collection to 20
    ASSERT_GT(collection->size(), prevCollection); //verifies that collection->size() is greater than previous collection

}


//Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, ReszingDecreasesCollection) {

    add_entries(15); //adds 15 enteries to the collection
    int prevCollection = collection->size(); //creating a temp holder for collection
    collection->resize(1); // resizes the collection to 1
    ASSERT_LT(collection->size(), prevCollection); //verifies that colelction->size() is less than prevCollection
}

//Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, VerifyResizeDecreaseToZero) {

    add_entries(10); //adding 10 entries to the collection
    collection->resize(0); //resizing the collection to 0
    ASSERT_EQ(collection->size(), 0); //this statement will check if collection->size is now equal to 0 after resize

}


//Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection) {

    add_entries(10); //start by adding 10 entries to the collection
    collection->clear(); //using clear to clear/erase the entriest in collection
    ASSERT_EQ(collection->size(), 0); //using ASSERT_EQ to validate the size of the collection is 0

}

//Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, VerificationOfErase) {

    add_entries(10); //adding 10 entries to the collection
    collection->erase(collection->begin(), collection->end()); //using erase method to erase begining to end of the collection
    ASSERT_EQ(collection->size(), 0); //using ASSERT_EQ to verify that the collection size is 0


}

//Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacity) {

    add_entries(10); //adding 10 entries to the collection
    int prevSize = collection->size(); //creating temp holder for size
    int prevCapacity = collection->capacity(); //creating temp holder for capacity
    collection->reserve(40); // reserving capacity in collection to size 40
    ASSERT_EQ(collection->size(), prevSize); //comparing size is equavilant to previous size
    ASSERT_GT(collection->capacity(), prevCapacity); // capacity now should be greater than previous capacity

}


//Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
//NOTE: This is a negative test
TEST_F(CollectionTest, OutOfRangeExceptionThrown) {

    std::vector<int> vector(20); //creating a vector with size of 20
    EXPECT_THROW(vector.at(30), std::out_of_range); // throw out_of_range exception if calling at() with an out of bounds index

}


//Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

TEST_F(CollectionTest, CustomTest1) { //negative test

    add_entries(10); //adds 10 entries to the collection
    collection->pop_back(); //pops the last entry from collection
    ASSERT_NE(collection->size(), 10); //compares the value of the 10th index within the collection

}

TEST_F(CollectionTest, CustomTest2) { //positive test

    add_entries(10); //adds 10 entries to the collection
    collection->push_back(1); //will push index 1 to the end of the collection
    ASSERT_GT(collection->size(), 10); // checks that the collection size is greater than 10
    EXPECT_EQ(collection->at(10), 1); //checks that the value at index 10 is 1
}