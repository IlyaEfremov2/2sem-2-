#include "CppUnitTest.h"
#include "../decicion/Prioritet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrioritetTests
{
    TEST_CLASS(PrioritetConstructionTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesEmptyQueue)
        {
            Prioritet pq;
            Assert::IsTrue(pq.is_empty());
            Assert::AreEqual(0, (int)pq.size());
            Assert::AreEqual(std::string(""), pq.str());
        }

        TEST_METHOD(InitializerListConstructor_CreatesCorrectQueue)
        {
            Prioritet pq = { {10, 3}, {20, 1}, {30, 5} };
            Assert::AreEqual(3, (int)pq.size());
            Assert::AreEqual(std::string("[30(5)] [10(3)]  [20(1)]"), pq.str());
        }

        TEST_METHOD(CopyConstructor_MakesDeepCopy)
        {
            Prioritet pq1 = { {1, 2}, {3, 4} };
            Prioritet pq2(pq1);

            Assert::AreEqual(pq1.str(), pq2.str());
            pq1.add(5, 6);
            Assert::AreNotEqual(pq1.str(), pq2.str());
        }

        TEST_METHOD(MoveConstructor_TransfersOwnership)
        {
            Prioritet pq1 = { {10, 2}, {20, 3} };
            std::string original = pq1.str();
            Prioritet pq2(std::move(pq1));

            Assert::AreEqual(original, pq2.str());
            Assert::IsTrue(pq1.is_empty());
        }
    };

    TEST_CLASS(PrioritetAssignmentTests)
    {
    public:
        TEST_METHOD(CopyAssignment_MakesDeepCopy)
        {
            Prioritet pq1 = { {1, 2}, {3, 4} };
            Prioritet pq2;
            pq2 = pq1;

            Assert::AreEqual(pq1.str(), pq2.str());
            pq1.add(5, 6);
            Assert::AreNotEqual(pq1.str(), pq2.str());
        }

        TEST_METHOD(MoveAssignment_TransfersOwnership)
        {
            Prioritet pq1 = { {10, 2}, {20, 3} };
            std::string original = pq1.str();
            Prioritet pq2;
            pq2 = std::move(pq1);

            Assert::AreEqual(original, pq2.str());
            Assert::IsTrue(pq1.is_empty());
        }
    };

    TEST_CLASS(PrioritetOperationTests)
    {
    public:
        TEST_METHOD(Add_InsertsElementsWithPriority)
        {
            Prioritet pq;
            pq.add(10, 2);
            pq.add(20, 3);
            pq.add(30, 1);

            Assert::AreEqual(3, (int)pq.size());
            Assert::AreEqual(std::string("[20(3)] ? [10(2)] ? [30(1)]"), pq.str());
        }

        TEST_METHOD(RemoveHigh_ExtractsHighestPriority)
        {
            Prioritet pq = { {10, 2}, {20, 3}, {30, 1} };
            int val;

            Assert::IsTrue(pq.removeHigh(val));
            Assert::AreEqual(20, val);
            Assert::AreEqual(2, (int)pq.size());
        }

        TEST_METHOD(RemoveLow_ExtractsLowestPriority)
        {
            Prioritet pq = { {10, 2}, {20, 3}, {30, 1} };
            int val;

            Assert::IsTrue(pq.removeLow(val));
            Assert::AreEqual(30, val);
            Assert::AreEqual(2, (int)pq.size());
        }

        TEST_METHOD(CheckHigh_PeeksWithoutRemoval)
        {
            Prioritet pq = { {10, 2}, {20, 3} };
            int val;

            Assert::IsTrue(pq.checkHigh(val));
            Assert::AreEqual(20, val);
            Assert::AreEqual(2, (int)pq.size());
        }

        TEST_METHOD(CheckLow_PeeksWithoutRemoval)
        {
            Prioritet pq = { {10, 2}, {20, 3}, {30, 1} };
            int val;

            Assert::IsTrue(pq.checkLow(val));
            Assert::AreEqual(30, val);
            Assert::AreEqual(3, (int)pq.size());
        }
    };

    TEST_CLASS(PrioritetOperatorTests)
    {
    public:
        TEST_METHOD(InsertOperator_AddsElements)
        {
            Prioritet pq;
            pq << std::make_pair(10, 2);
            pq << std::make_pair(20, 3);

            Assert::AreEqual(2, (int)pq.size());
            Assert::AreEqual(std::string("[20(3)] ? [10(2)]"), pq.str());
        }

        TEST_METHOD(ExtractOperator_RemovesElements)
        {
            Prioritet pq = { {10, 2}, {20, 3} };
            std::pair<int, int> elem;

            pq >> elem;
            Assert::AreEqual(20, elem.first);
            Assert::AreEqual(3, elem.second);
            Assert::AreEqual(1, (int)pq.size());
        }
    };

    TEST_CLASS(PrioritetEdgeCaseTests)
    {
    public:
        TEST_METHOD(EmptyQueueOperations)
        {
            Prioritet pq;
            int val;

            Assert::IsFalse(pq.removeHigh(val));
            Assert::IsFalse(pq.removeLow(val));
            Assert::IsFalse(pq.checkHigh(val));
            Assert::IsFalse(pq.checkLow(val));
        }

        TEST_METHOD(SingleElementQueue)
        {
            Prioritet pq;
            pq.add(10, 1);
            int val;

            Assert::IsTrue(pq.removeHigh(val));
            Assert::AreEqual(10, val);
            Assert::IsTrue(pq.is_empty());
        }

        TEST_METHOD(EqualPriorities_MaintainsOrder)
        {
            Prioritet pq = { {10, 1}, {20, 1}, {30, 1} };
            Assert::AreEqual(std::string("[10(1)]  [20(1)]  [30(1)]"), pq.str());
        }

        TEST_METHOD(ClearQueue_RemovesAllElements)
        {
            Prioritet pq = { {1, 1}, {2, 2}, {3, 3} };
            pq.purge();

            Assert::IsTrue(pq.is_empty());
            Assert::AreEqual(0, (int)pq.size());
        }
    };
}