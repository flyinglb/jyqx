// Room: /d/huashan/luoyan.c

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�Ϸ���������壬�ǻ�ɽ��߷塣��ͷ��̼��࣬�硰̫����ͷ��������
�����족����������ǡ��ȣ����Ի���֮�ߡ��������ܣ��������¡���׼ʫ��
Ի��ֻ�������ϣ�����ɽ���룻��ͷ���ս������װ��Ƶ͡���˵���ʱ�����
ʿ���Ҿ������������̫��������گ������ɽ���٣�����������д��лگ��
˵����һƬҰ�Ķ���������ס�����س�گ�ݽ̵�������������ʾ��Ը��ɽ���١�
LONG
        );
        set("objects", ([
//            CLASS_D("huashan") + "/feng-qingyang":1,
            CLASS_D("huashan") + "/feng" : 1,
        ]));
        set("exits", ([ /* sizeof() == 4 */
           "northdown" : __DIR__"zhandao",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

