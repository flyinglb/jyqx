// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("С����", ({"small box", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("long",
"��ֻ����С�öֻ࣬һ�߼���������һ�ż���д��������
���Һ����ߣ����Һ��ǣ��������ر������������п���ʱ
�ж���������������׵�ͼ���٣����о綾���Գ�̰����
ͽ�������ڴ�С�����ڡ���\n");
        	set("unit", "ֻ");
        set("no_sell", 1);
        	set("open_count", 1);
        	set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
        object ob, me = this_player();
	if (query("open_count") > 0)
	{
       	        message_vision(HIR 
"$N���ִ����У��������������飬��д���������š����֣���
ǯ�ӽҿ���ҳ����д������С�֣��������ͼ�����е��ǵ�ͼ��
�е����������ƣ�����Щ���л��ص�ͼ����\n" NOR, this_player());
	        add("open_count", -1);
                ob = new("/clone/book/jinshe1");
                ob -> move(me);
                ob = new("/clone/book/jinshe2");
                ob -> move(me);
                ob = new("/clone/book/jinshe3");
                ob -> move(me);
                return 1;
        }
        else return notify_fail("�����Ѿ������˴򿪹��ˡ�\n");
}
