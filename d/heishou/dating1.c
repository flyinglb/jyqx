inherit ROOM;
#include <mudlib.h>
void create()
{
        set("short", "����");
        set("long", @LONG
������ָɽׯ����������Ȼ������װ��û��ʲô������ɨ��ʮ�ָ�
��������Ҳ��Ϊ���㡣�ıڹ���һЩ�����黭��Ʒ����Ϊ�ϳ�֮������
�������۹ⲻ�������д������֡�
LONG );
        set("valid_startroom",1);
        set("no_steal", "1");
        set("no_sleep_room", "1");
        set("no_fight","1");
        set("item_desc",([
//                "duilian" : "�����ɵ���ƮѪ�����츣��������\n",
        ]));
        set("exits", ([
                "south"  : __DIR__"qianyuan",
                "north"  : __DIR__"huiyi",
                "west"  : __DIR__"eatroom3",
                "east"  : __DIR__"ligong",
        ]));
        setup();
        "/clone/board/heishou_b"->foo();

        }

