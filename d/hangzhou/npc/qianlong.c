 // qianlong.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("Ǭ¡�ʵ�", ({ "qianlong", "emperor"}) );
        set("title", "�����");
        set("gender", "����");
        set("age", 43);
        set("per", 24);
        set("long",
"Ǭ¡�ʵ��հ��¾��ޣ����������Ǵ�����غ����λ��λ�ʵۣ���ƽ
�ų���ʮ���书���Գơ�ʮȫ���ˡ���\n");
        set("combat_exp", 500);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 30);
}
void init()
{
        add_action("do_kneel", "kneel");
}

int do_kneel()
{
        int i;
        object *chen, me = this_player();
        if( base_name(environment()) != "/d/hangzhou/liuhed") {
                tell_room(environment(), name() +"�󾪵�:������ô���ҵ������˵��ת����ܡ�\n");
                destruct(this_object());
        }

        if ( objectp(present("chen jialuo", environment(me))))
        {
              message_vision(
"$N�����Ǭ¡�ʵ��밲��ȴ���¼���һ����ס�����ӵ�ӥȮ��
��Ҫ����ū�ţ��������ɣ�\n\n", me);
              chen = all_inventory(environment(me));
              for(i=0; i<sizeof(chen); i++)
              {
                   if( chen[i] -> query("id") == "chen jialuo")
                       chen[i]->kill_ob(me);
              }
        }
        message_vision(
"$N���������ع�����������ͷ����ū��"+me->query("name")+"�ȼ����٣�����ˡū�����\n\n", me);
        if( me->query("combat_exp") < 150000 )
        {
              message_vision(
"$n����$N������һ�����㵨���۾�ð����ƾ���������Ҳ�����˺컨�᣿��\n\n", me, this_object() );
              message_vision(
"$n����һ�ţ��ߵ�$NѾ��Ѿ�Ź���������ȥ�ˡ�\n\n", me, this_object() );
              me->move("/d/hangzhou/liuheta");
              tell_object(me, HIR"���������һ���������������ۣ��������ˡ�\n"NOR);
message("vision", HIR"ֻ��" + me->query("name") + "����������ͨһ���������������ڵ��ϰ�������������\n"NOR, environment(me), me);
              me->receive_wound("qi", 20);
              me->add("combat_exp", 0 - me->query("combat_exp") /100);
              return 1;
        }
        if( me->query("marks/qianlong") )
        {
              message_vision(
"$n����$N������һ����û��$N��\n\n", me, this_object() );
        }
        else
        {
              message_vision(
"$n����$N˵�������ˣ�������ȼ��й���������������з��͡�\n\n", me, this_object() );
              me->set("marks/qianlong", 1);
              me->add("combat_exp", 10000);
        }
        return 1;
}

