// yuan.c Ԩ�� 

inherit ROOM;
#include <ansi.h> 

void init();
void create()
{
        set("short", "����Ԩ��");
        set("long", @LONG
���˷����£���ͷ�������������ȣ��������������뻹�е�
���£����Ͼ������ˡ���ǰ���������������ˣ����������д�˵
�����ǣ����ڳ���������ǰ�ˣ��Ͽ��ȥ�����ɡ�  
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            "north" : __DIR__"shanya",
            "south" : __DIR__"bingqiao",
        ]));
        set("item_desc", ([
      "bridge" : "����һ����׾�Ө�ı��š�\n",
        ]) );
        setup();
}


