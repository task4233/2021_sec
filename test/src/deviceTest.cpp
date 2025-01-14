#include "../include/test.hpp"

using namespace std;

TEST(deviceTest, usbList)
{
	device_c usb;
	vector<string> usb_list;
	usb_list = usb.get_usbList();
	ASSERT_FALSE(usb_list.empty());
	cout << "usblist" << endl;
	for (string usb : usb_list)
	{
		cout << usb << endl;
	}
}

TEST(deviceTest, setUsbID)
{
	device_c usb;
	ERROR_TEST;
	ASSERT_FALSE(usb.set_usbID("hoge"));
	ASSERT_FALSE(usb.set_usbID(""));
	ASSERT_FALSE(usb.set_usbID("1d6b:000"));
	ASSERT_FALSE(usb.set_usbID("1d6b:0005"));
	TEST_END;

	ASSERT_TRUE(usb.set_usbID("1d6b:0002"));
	string temp = usb.get_usbID();
	ASSERT_STREQ("1d6b:0002", temp.c_str());
	temp.clear();
	temp = usb.get_usbSerial();
	ASSERT_STREQ("0000:00:0b.0", temp.c_str());
}