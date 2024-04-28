#include <iostream>
#include <set>
using namespace std;

class Set
{
private:
    set<int> elements;

public:
    void add(int element)
    {
        elements.insert(element);
    }

    void remove(int element)
    {
        elements.erase(element);
    }

    bool contains(int element) const
    {
        return elements.count(element) > 0;
    }

    int size()
    {
        return elements.size();
    }

    void print()
    {
        for (int element : elements)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    Set intersection(const Set &other)
    {
        Set result;
        for (int element : elements)
        {
            if (other.contains(element))
            {
                result.add(element);
            }
        }
        return result;
    }

    Set unionSet(const Set &other)
    {
        Set result;
        for (int element : elements)
        {
            result.add(element);
        }
        for (int element : other.elements)
        {
            result.add(element);
        }
        return result;
    }

    Set difference(const Set &other)
    {
        Set result;
        for (int element : elements)
        {
            if (!other.contains(element))
            {
                result.add(element);
            }
        }
        return result;
    }

    bool subset(const Set &other)
    {
        for (int element : elements)
        {
            if (!other.contains(element))
            {
                return false;
            }
        }
        return true;
    }

    class Iterator
    {
    private:
        set<int>::iterator it;

    public:
        Iterator(set<int>::iterator iterator) : it(iterator) {}

        int operator*()
        {
            return *it;
        }

        Iterator operator++()
        {
            ++it;
            return *this;
        }

        bool operator!=(const Iterator &other)
        {
            return it != other.it;
        }
    };

    Iterator begin()
    {
        return Iterator(elements.begin());
    }

    Iterator end()
    {
        return Iterator(elements.end());
    }
};

int main()
{
    Set set;
    int choice, element;
    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Add\n";
        cout << "2. Remove\n";
        cout << "3. Contains\n";
        cout << "4. Size\n";
        cout << "5. Print\n";
        cout << "6. Intersection\n";
        cout << "7. Union\n";
        cout << "8. Difference\n";
        cout << "9. Subset\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to add: ";
            cin >> element;
            set.add(element);
            break;
        case 2:
            cout << "Enter element to remove: ";
            cin >> element;
            set.remove(element);
            break;
        case 3:
            cout << "Enter element to check: ";
            cin >> element;
            if (set.contains(element))
            {
                cout << "Element is in the set.\n";
            }
            else
            {
                cout << "Element is not in the set.\n";
            }
            break;
        case 4:
            cout << "Size of the set: " << set.size() << endl;
            break;
        case 5:
            cout << "Elements in the set: ";
            for (int element : set)
            {
                cout << element << " ";
            }
            cout << endl;
            break;
        case 6:
        {
            Set intersectionSet;
            cout << "Enter elements of the other set (0 to stop):\n";
            while (true)
            {
                cin >> element;
                if (element == 0)
                {
                    break;
                }
                intersectionSet.add(element);
            }
            Set result = set.intersection(intersectionSet);
            cout << "Intersection of the sets: ";
            for (int element : result)
            {
                cout << element << " ";
            }
            cout << endl;
            break;
        }
        case 7:
        {
            Set unionSet;
            cout << "Enter elements of the other set (0 to stop):\n";
            while (true)
            {
                cin >> element;
                if (element == 0)
                {
                    break;
                }
                unionSet.add(element);
            }
            Set result = set.unionSet(unionSet);
            cout << "Union of the sets: ";
            for (int element : result)
            {
                cout << element << " ";
            }
            cout << endl;
            break;
        }
        case 8:
        {
            Set differenceSet;
            cout << "Enter elements of the other set (0 to stop):\n";
            while (true)
            {
                cin >> element;
                if (element == 0)
                {
                    break;
                }
                differenceSet.add(element);
            }
            Set result = set.difference(differenceSet);
            cout << "Difference of the sets: ";
            for (int element : result)
            {
                cout << element << " ";
            }
            cout << endl;
            break;
        }
        case 9:
        {
            Set otherSet;
            cout << "Enter elements of the other set (0 to stop):\n";
            while (true)
            {
                cin >> element;
                if (element == 0)
                {
                    break;
                }
                otherSet.add(element);
            }
            if (set.subset(otherSet))
            {
                cout << "The set is a subset of the other set.\n";
            }
            else
            {
                cout << "The set is not a subset of the other set.\n";
            }
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}