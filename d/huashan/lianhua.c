// Room: /d/huashan/lianhua.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
̫�����壭���������壬Ҳ��ܽ�ط壬�嶥��һ���ʯ��״������������
���ۡ��ô��ɴ˵������������¶��ͣ�����ǧ�𣬵���Զ�����ش�çç��μ��
���ˮ����������嶥��ʯ����ժ��ʯ����ȡ���ֿ�ժ�ǳ���֮�⣬��״����
֮�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
             "eastdown" : __DIR__"chengxiang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan");

        setup();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/lianhua", 1);
        return;
}
