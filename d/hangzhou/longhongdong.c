// longhongdong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ֽ�ͨ�춴���ڶ��ڵ��ұ��Ͽ�����̬���죬һ�ɶ�ߵķ�����
�����·������鸡��ǰһ���������ɮȡ���Ĺ��£���һ��Ϊ��
���Ծ������С��÷�����������Ħ�ڡ���������������ɽ��·��С·
����������������
LONG);
        set("exits", ([
                "northwest" : __DIR__"shexudong",
                "eastdown"  : __DIR__"feilaifeng",
        ]));

        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
