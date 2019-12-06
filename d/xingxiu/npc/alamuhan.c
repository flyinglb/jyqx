// npc: /d/xingxiu/npc/alamuhan.c
// Jay 3/17/96

inherit NPC;

int ask_me();
int do_qiecuo();

void create()
{
        set_name("����ľ��", ({ "alamuhan", "ala", "muhan" }));
        set("long", "����β���Ҳ���ݡ�����üë�����£������۾��ܶ��顣\n");
        set("title", "�������");
        set("gender", "Ů��");
        set("age", 17);

        set_skill("unarmed", 20);
        set_skill("dodge", 40);
        set_skill("parry", 20);
        set_skill("whip", 50);

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 5000);
        set("attitude","friendly");
        set("inquiry", ([
                "����׷" : (: ask_me :),
		"����" : (: ask_me :),
                "��" : (: ask_me :),
        ]) );

        set("shen_type", 1);
        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/changbian")->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
        if ((int)this_player()->query_temp("marks/��")) {
                say(
"����ľ����" + this_player()->name() + "˵�����⺢����ô�ϲ��ű����\n");
                return 1;
        } else {
        say(
"����ľ������" + this_player()->name() + "һ�ۣ��ò�̫��׼�ĺ���˵����\n"
"������������ı޷�ҲС�е����������λ����" + RANK_D->query_respect(this_player()) + "\n"
"�벻������д꼸��?\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
        }
}

int accept_fight(object ob)
{
        object me;

        me = this_object();
      
        if( ob->query_temp("marks/��1") ) {
           say(ob->name() + "�԰���ľ��˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          ob->set_temp("marks/��1", 0);
          return 1;
        }
        else
    	  return 0;
}

int checking(object me, object ob)
{

        object horse;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "����ľ��˵����ԭ��ѧ��Ȼ��һ�㣬СŮ��ʮ�������\n"
                  "����һƥ�������Ա���ġ�\n"
                );
                horse = new(__DIR__"obj/horse"); 
                horse->move(ob);
                ob->set_temp("marks/��", 1);
                message_vision("$N����$nһƥ��\n", me, ob);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "����ľ������" + ob->name() + "Ʋ��Ʋ�죬˵������ԭ��ѧ������ˡ�\n"
                );
                message("vision",
                   ob->name() + "�԰���ľ�����������ؿ���һ��ͷ���뿪������\n", environment(ob), ({ob}) );
                ob->move("/d/xingxiu/beijiang");
                message("vision",
                   ob->name() + "��������ͷɥ�����߻�����\n", environment(ob), ({ob}) );
                return 1;
        }
        return 1;
}


