// hehongyao.c
// �κ�ҩ
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�κ�ҩ", ({ "he hongyao", "he" }));
        set("nickname", HIG "����ؤ��" NOR);
        set("long",@LONG
�������嶾�̵ĳ��ϣ������Ĺùúκ�ҩ����Ȼ�ǽ����ĳ�����������ȴ��һ���
�ϴ�����ѧ�ġ���˵����������Ϊ�����̳��ˣ����������´�����Ա������˴�
����ʥ�أ�����ǰ�������һ���ƾɵ������������̺ۣ����ù������˫Ŀ��
����Թ��֮ɫ��
LONG
        );
        set("title","�嶾�̳���");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("wudu-shengong", 200);
        set_skill("dodge", 190);
        set_skill("wudu-yanluobu", 150);
        set_skill("unarmed", 160);
        set_skill("qianzhu-wandushou", 160);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 180);
        set_skill("duji", 160);
        set_skill("literate", 80);
//      set_skill("hammer", 100);
//      set_skill("jinshe-chui", 150 );
//      set_skill("huoyan-dao", 200);



        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
//      map_skill("strike","huoyan-dao");

        create_family("�嶾��", 11, "����");

        setup();

        carry_object(__DIR__"obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuxing");

        add_money("gold",10);
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
        ob->set("class", "none");
	 ob->set("title",HIY"�嶾�̻���"NOR);
       return;
}
