#ifndef FAMILY_H
#define FAMILY_H

#include <string>
#include <iostream>
class Child;
class Mother {
    private:
        
    public:
        
        Mother();
        
        void setNameOfChild(Child& child, const std::string& name);
};

class Father {
    private:
        
    public:
        
        Father();
        template <typename T>
        void combatAssignment(const Child& child, T object) {
        
            std::cout << child.name << " holding " << object << std::endl;
        }   
};

class FriendFromSchool {
    private:
        
    public:
       
       const std::string  play(Child& child);
};

class Child {
    private:
        std::string name;
        void setName(const std::string& name);
    public:
        Child(const std::string& name);

        friend class Mother;
        friend class Father;
        std::string getName() const;
        friend const std::string FriendFromSchool::play(Child& child);
        
};

#endif // FAMILY_H