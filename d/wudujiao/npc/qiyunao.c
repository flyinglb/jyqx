// qiyunao.c
// ���ư�
// by victori
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���ư�", ({ "qi yunao", "qi" }));
        set("nickname", HIG "���¶�ؤ" NOR);
        set("long",@LONG
�������嶾�̵ĳ��ϣ��˳ƽ��¶�ؤ�����ư������ǽ�����ͬ��ʦ�֣��ڽ���
һ�������裬��Ȩ��������������Ŀ��࣬��Ŀ��������һ����ʽ��£�̫��
Ѩ�߸߷���
LONG
        );
        set("title","�嶾�̳���");
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 30);
        set("dex", 20);
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 1000000);
        set("score", 500000);
        set_skill("force", 170);
        set_skill("wudu-shengong", 170);
        set_skill("dodge", 160);
        set_skill("wudu-yanluobu", 150);
        set_skill("unarmed", 200);
        set_skill("qianzhu-wandushou", 180);
        set_skill("parry", 200);
        set_skill("sword", 170);
        set_skill("wudu-goufa", 170);
        set_skill("duji", 150);
        set_skill("literate", 80);
//      set_skill("hammer", 200);
//      set_skill("jinshe-chui", 180 );
//      set_skill("strike", 200 );
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
 
        create_family("�嶾��", 11, "����");
	 set("jinshe_count", 1);
        set("chat_chance",5);
        set("chat_msg",({
	 "\n���ư�ŭ��������������ȥ�����������������ഴ�µĻ�ҵ��Ҫ�����������ˡ�\n"NOR,
	 "\n���ư�������������������ҵ������������Ķ�ʥ�������֮λ�����ҵ��ˡ�\n"NOR,
//        (:random_move:)
    	}));
        setup();
//      carry_object(__DIR__"obj/jinshezhui")->wield();
        carry_object(__DIR__"obj/jinyi")->wear();
        carry_object(__DIR__"obj/dujing3");
        add_money("silver",20);
}
void attempt_apprentice(object ob)
{
 		  if ((string)ob->query("gender") == "����") {
        			 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
		  }
		  if ((int)ob->query("shen") > -10000) {
        			 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
                return;
		  }
        if ((string)ob->query("family/family_name") != "�嶾��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���Ǳ��̵��ӣ�������ذɣ�");
                return;
		  }
        if ((int)ob->query_skill("duji", 1) < 100) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }
          command("chat �ٺٺٺ٣���������");
          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
          command("chat �ٺٺٺ٣���������");
          command("recruit " + ob->query("id"));
	 ob->set("title",HIY"�嶾�̻���"NOR);
        ob->set("class", "none");
        return;
}
int accept_object(object who, object ob)
{
	object obn;
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
	if ( (string)ob->query("name") != HIC "������" NOR )
		    return notify_fail("���ư�ҡͷ������Щ���ö���������ʲô�ð���\n");
	 message_vision("\n���ư����������㣬��ϲ�����⡢�����������������̫���ˣ�\n",who);
//      destruct(ob);
        obn=new(__DIR__"obj/jinsheduye");
        obn->move(who);
	 message_vision("\n���ư�˵���������ϲ��ܰ�����Ķ���������һƿ���߶�Һ���͸���ɣ�\n",who);
 	          return 1;		 

}
