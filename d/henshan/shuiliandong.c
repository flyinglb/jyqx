// Room: /d/henshan/shuiliandong.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ˮ����");
        set("long", @LONG
ˮ�������ϸǷ��£����������¯����֮�䡣�ϸǷ�֮ˮ��ɽ����
���ϸ��ɶ��У���ɲ⣬ˮ�����磬���ٸ߶�ʮ���ɣ�����������Ʈ
й���£�εΪ׳�ۡ����ž���ʫԻ:  "����孺�������Ī�����ӵ���
��������������������ˮ����������ͷ��" ����̾���ɽ���ľ�֮һ��
 "ˮ����֮��" ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"    : __DIR__"shanlu12",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "henshan");
        setup();
        replace_program(ROOM);
}

