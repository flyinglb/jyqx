// Room: god1
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"����"NOR);
        set("long", HIC @LONG
����������á����ƶ�䣬ɫ������覣�����������ǰƮ�����Ǵ���ɫһ
Ƭ�Ĳݵ��Ͽ�����ɫ�ʸ�����ʻ����������Ʋ�ɢ�����ſ��ţ��㶼��Ҫ���ˡ�
Զ��һ����׵Ĺ��ΡȻ�������������Ƕ������������֣����ɺ����ö�����
�����ţ�������Լ������鶼�ѵ��˵��������Ӵ������˷������������������
һ�ж�������ð�Ȼ���������������顭��
LONG
NOR   );
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 2 */
            "up" : __DIR__"god2",
            "down": "/d/city/wumiao",
        ]));
}

int valid_leave(object me, string dir)
{
        switch(dir) {
        case "up":      write(HIC"��������������������ʥ�\n"NOR);
                        return 1;
        case "down":    write(HIW"��Ҫ���ط����������𣿡���\n\n"NOR);break;
        default:
                        write(HIG"���������Ȼ�����Ѿ����Ǿ�ȥ�ɡ���\n\n"NOR);
        }
        write(HIB"ȥ�ɡ���ȥ�ɡ���һ�����������˵����\n\n\n\n"NOR);
        write(HIY"����º�Ȼ����һ�����ƣ���һ̤��ȥ������������Ʈȥ�ˣ�����\n\n\n\n"NOR);
        me->reincarnate();
/*
        me->add("combat_exp", (int)me->query("combat_exp") / 49);
        me->add("potential", 50);
        me->add("max_neili", 2);
        me->set("eff_jing",(int)me->query("max_jing"));
        me->set("eff_qi",(int)me->query("max_qi"));
        me->set("jing",(int)me->query("eff_jing"));
        me->set("qi",(int)me->query("eff_qi"));
        me->skill_soo_reincarnate();
*/
	return 1;
}
