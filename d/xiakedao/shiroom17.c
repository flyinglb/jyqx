// /d/xiakedao/shiroom17.c ���͵� ʯ��17

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������֮��������һ����İ�С�ĺ����ֳֻƽ������ʹ��ü
�̵��ٸ�˫սһ�����ӡ���������һƬ�ƹ������λζ���˿��������
�硣���о��缤��֮�£����ҲϨ������֧��ʯ��(wall)�ϵ�ͼ����
Լ�ɼ���
LONG );
        set("exits", ([
                "south" : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š����Իӽ�鳡��������֡������ͼ������׳������
�����ˡ����������´��ƽ�����˴���������ֻ����ǹ���գ�Ѫ
���ɡ��Ա�ע�Ͳ��࣬���Ǳ����۽���
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
