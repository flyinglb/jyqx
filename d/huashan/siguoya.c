// siguoya.c
// Dec.11 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "˼����");
        set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ��������
�ܷ�֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ
����Ů�����ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮����
��Ҫ�Ǵ˴��޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ��
�����ţ��������͡�
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        setup();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
        return;
}
