// heersu.c
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_he();

void create()
{
	set_name("�ն���", ({"heersu"}));
	set("gender", "����");
	set("age", 65);
	set("long", 
		"����һ���ϲοͣ�����һƶ��ϴ��\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);

	set("inquiry",([
		"�˲�"    :     (: ask_me :),
		"ɽ��"    :     (: ask_me :),
		"��"      :     (: ask_me :),
		"������"  :     (: ask_he :),
		"����"    :     (: ask_he :)
	]));
	set("item_count",1);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
         object me;
	
	me = this_player();
	if((int)(me->query("shen")<0)) return "���������������类�����ˣ�û���ˡ�\n";
	me -> set_temp("�˲�",1);
	return "������ó�Ǯ���ɡ�\n";
}
string ask_he()
{
         object me;
	
	me = this_player();
	if((int)(me->query("shen")<0)) return "�����������������类�����ˣ�û���ˡ�\n";
	me -> set_temp("����",1);
	return "������ó�Ǯ���ɡ�\n";
}

int accept_object(object me, object ob)
{
	object obj;
    if (!(int)me->query_temp("�˲�") && !(int)me->query_temp("����"))
    {
	message_vision("�ն��ջֵ̿ض�$N˵���Ҳ���Ҫ���ϵ�Ǯ��\n", me);
	return 0 ;
    }
    if (ob->query("money_id") && ob->value() >= 50000)
    {
       if ((int)me->query_temp("����"))
       {
           if (query("item_count")>0)
           {
message_vision("�ն��ն�$N˵���ã���Ȼ��λ" + RANK_D->query_respect(me) +
     "��˿���������ͷ�ӣ�\n������������˺ܾ��ˣ����͸���ɣ�\n" , me);
               me->delete_temp("����");
               obj = new("/d/city/obj/shouwu");
               obj -> move(me);
               add("item_count", -1);
           }
           else
message_vision("�ն��ն�$N˵��Ǯ�������ţ�������ʱ��˵�ɣ�\n", me);
       } else
       {
           if (query("item_count")>0)
           {
message_vision("�ն��ն�$N˵���ã���Ȼ��λ" + RANK_D->query_respect(me) +
     "��˿���������ͷ�ӣ�\n��ò������˺ܾ��ˣ����͸���ɣ�\n" , me);
               me->delete_temp("�˲�");
               obj = new("/d/city/obj/shanshen");
               obj -> move(me);
               add("item_count", -1);
           }
           else
message_vision("�ն��ն�$N˵��Ǯ�������ţ���һ���Ҹ�������ɽ�θ�����\n", me);
       }
    }
    else  
	message_vision("�ն�����ü��$N˵��������Ҳ̫���˰ɣ�\n", me);
    return 1;
}

