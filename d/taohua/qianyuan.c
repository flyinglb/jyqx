#include <room.h>

inherit ROOM;

void create()
{
    set("short", "�һ�ɽׯǰԺ");
    set("long", @LONG
��������վ��һ������Ժ���С�Ժ��ԭ������Ϊ���䳡��
�ġ����Դ��һ������ӱ���ҩʦ������⣬���Ѿ�û���ڴ����䡣
�����Ǳ����ң������ǳ��������Ͼ����һ�ɽׯ�����ˡ�
LONG );
    set("exits", ([
        "north" : __DIR__"damen",
        "south" : __DIR__"dating",
        "east"  : __DIR__"bingqi",
        "west"  : __DIR__"chufang",
    ]));
    set("outdoors", "taohua");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
