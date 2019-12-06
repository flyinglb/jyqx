// panxiuda.c
// �����
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "pan xiuda", "pan" }));
        set("nickname", HIG "Ц������" NOR);
        set("long",@LONG
�������嶾�̵��󻤷����˳�Ц�����޵���������һ��Ц���е�
�����ǳ���ɱ���ڵ�ָ֮�䣬һ���嶾����Ҳ�Ѵﵽ�Ƿ��켫�ľ��硣
LONG
        );
        set("title","�嶾�̻���");
        set("gender", "����");
        set("age", 38);
        set("shen_type", -1);
        set("str", 30);
        set("attitude","peaceful");
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("score", 50000);

        set_skill("force", 120);
        set_skill("wudu-shengong", 120);
        set_skill("dodge", 130);
        set_skill("wudu-yanluobu", 110);
        set_skill("unarmed", 120);
        set_skill("qianzhu-wandushou", 120);
        set_skill("parry", 120);
        set_skill("sword", 140);
        set_skill("wudu-goufa", 140);
        set_skill("duji", 110);
        set_skill("literate", 80);
//        set_skill("hammer", 100);
//       set_skill("jinshe-chui", 140 );
//      set_skill("strike", 200 );
 


        map_skill("force", "wudu-goufa");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");
 
        create_family("�嶾��", 12, "����");

        setup();

        carry_object(__DIR__"obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver",10);
}

void attempt_apprentice(object ob)
{

 		  if ((string)ob->query("gender") == "����") {
        			 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
		  }

		  if ((int)ob->query("shen") > -5000) {
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

        if ((int)ob->query_skill("duji", 1) < 60) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 60) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }

//          command("chat �ٺٺٺ٣���������");
//          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
//          command("chat �ٺٺٺ٣���������");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");

	 ob->set("title",HIY"�嶾�̵���"NOR);
         return;
}
