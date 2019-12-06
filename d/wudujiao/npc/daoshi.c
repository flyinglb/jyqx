// daoshi.c
// by victori
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
inherit F_MASTER;
int ask_me();

void create()
{
	set_name("�η�����", ({ "dao ren", "dao", "daoren" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"һ���׾����ֵĵ�ʿ����˭��Ц���еģ������е�Ʒ��һ����衣\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("rank_info/respect", "Ц������");
	set_skill("dodge", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("force",80);
	set_skill("hammer", 80);
	set_skill("duji", 80);
	set_skill("sword",80);
	set_skill("literate", 50);
	set_skill("wudu-yanluobu", 70);
	set_skill("qianzhu-wandushou", 75);
	set_skill("wudu-shengong", 70);

        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "qianzhu-wandushou");
	set("vendor_goods", ({
  	       __DIR__"obj/jiedudan",
	}));
       create_family("�嶾��", 13, "��������");
	setup();
	carry_object("/clone/misc/cloth")->wear();
       add_money("silver",30);
set("inquiry", ([
"�嶾��": (: ask_me :),
]) );
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "�η����˺ٺ�һ���Ц������λ" + RANK_D->query_respect(ob)
				+ "��Ҳ����ס�����\n");
			break;
		case 1:
			say( "�η����˵��˵��ֵ�����λ" + RANK_D->query_respect(ob)
				+ "���������������Ҫȥ�ǰ���\n");
			break;
		case 2:
			say( "�η��������־���֮ɫ������λ" + RANK_D->query_respect(ob)
				+ "ü�ֺ��������ջ��д��ѡ�\nƶ����һЩ��������������㣬����ɾ���һ����\n");
			break;
	}
}
void attempt_apprentice(object ob)
{

 		  if ((string)ob->query("gender") == "����") {
        			 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
		  }

		  if ((int)ob->query("shen") > 1000) {
        			 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say �ҽ̵��ӹ�����������������α����");
                return;
		  }


        command("recruit " + ob->query("id"));
        ob->set("class", "none");
	 ob->set("title",HIY"�嶾��ͽ"NOR);
       return;
}
int ask_me()
{
        object ob,me;
        me = this_player();
        if ((string)me->query("family/family_name") != "�嶾��")    
              return notify_fail("�Բ����޿ɷ�棡\n");
        command("say ��λ"+ RANK_D->query_respect(me)
               + "�������ã�����������Ҫ��ɽ���£�������������һ�̰ɡ�\n");
	 message_vision(HIC"�η�����һ���֣�һ����ʻ����ͣ����ǰ��\n$N��æ������У�ֻ��һ�����ı��죬��������ȥ��\n\n"NOR,me);
        ob = load_object("/d/wudujiao/damen");
        ob = find_object("/d/wudujiao/damen");
        message("vision", "Զ��һ������ʻ����������һ��"+me->query("name")+"���������˳�����\n", ob);
	 tell_object(me, "ֻ��������˵������λ"+ RANK_D->query_respect(me)
          + "�Ѿ����ˣ����³��ɡ�\n"NOR );
        me->move("/d/wudujiao/damen");
        return 1;

}


