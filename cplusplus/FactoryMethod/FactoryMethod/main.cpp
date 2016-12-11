#include <iostream>
#include <memory>

class Sender {
public:
    virtual void send() = 0;
};

class MailSender : public Sender {
public:
    virtual void send()
    {
        std::cout << "This is MailSender.\n";
    }
};

class SmsSender : public Sender {
public:
    virtual void send()
    {
        std::cout << "This is SmsSender.\n";
    }
};

class Factory {
public:
    virtual std::shared_ptr<Sender> create() = 0;
};

class MailSenderFactory : public Factory {
public:
    std::shared_ptr<Sender> create()
    {
        return std::make_shared<MailSender>(MailSender());
    }
};

class SmsSenderFactory : public Factory {
public:
    std::shared_ptr<Sender> create()
    {
        return std::make_shared<SmsSender>(SmsSender());
    }
};

int main(int argc, char* argv[])
{
    std::shared_ptr<Factory> factory(new MailSenderFactory);
    std::shared_ptr<Sender> sender = factory->create();
    sender->send();

    factory = std::make_shared<SmsSenderFactory>(SmsSenderFactory());
    sender = factory->create();
    sender->send();

    return 0;
}


