// /d/wizard/prison.c �����������ͷ����ҵ����
// byp@MX

#include <ansi.h>
inherit ROOM;

void check_release(object me);

void create()
{
        set("short", "����");
        set("long", @LONG
����ں�������ʲôҲ�����壬�����﷢��һ�����ŵĶ������������ʦ
ר�������ͷ���Щ������ҵġ��������ǵ��������һ�����ˡ���������ʵʵ
����˼���ɣ�
LONG
        );
        set("no_fight",1);
        set("no_get",1);
        set("no_beg",1);
        set("no_steal",1);
        set("no_get_from",1);
        set("no_beg_from",1);
        set("no_steal_from",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        object me = this_player();
        if(wizardp(me)) return;
        if( !me->query("prison")
        || ((int)me->query("prison/release_time") < 1) ) {
                me->delete("prison");
                me->move("/d/city/wumiao");
                me->set("startroom","/d/city/wumiao");
                message("vision", "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(me), me);
        } else me->set("startroom","/d/wizard/prison");
}
