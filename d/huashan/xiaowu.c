// Room: /d/huashan/xiaowu.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������ǻ�ɽ���ڵĵĸ���֮�ء���ʮ�����������ڵ�����н������
ֻ��Ϊ�˶�ػ�ɽ�������ţ�Ϊ�ˣ������˼���������
    ������輫Ϊ��ª����ô������һֱû�г����������ͷʹ�ý��ڵ�
�������踺�أ�ֻ���ؿ����졣
LONG );
        set("exits", ([ /* sizeof() == 4 */
             "west": __DIR__"pingdi",
        ]));
        set("objects", ([
             CLASS_D("huashan") + "/feng-buping": 1,
        ]));
        set("valid_startroom","1");
//        set("no_clean_up", 0);

        setup();
        "/clone/board/jianzong_b"->foo();
        replace_program(ROOM);
}

