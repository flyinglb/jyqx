// daoren.c
// by victori
inherit NPC;
int ask_me();
#include <ansi.h>
void create()
{
        set_name("������", ({ "dao ren","dao" }) );
        set("gender", "����" );
        set("age", 35);
	 set("per", 20);
        set("long", "һλ���������ɱ���ݵ�������ˣ�\n");
        set("combat_exp", 200000);
         set("attitude", "peaceful");
//      set("env/wimpy", 50);
	 set_skill("dodge", 80);
	 set_skill("unarmed",80);
	 set_skill("parry", 80);
	 set_skill("literate", 150);

	set("chat_chance",12);
  	set("chat_msg",({
	"��������Ц������������˭�Һ������嶾�����ԣ��ܽ������Ĳ������ס�\n",
	"�����и�Цһ������ƶ��ר�����Ƹ��ֶ�ҩ����֤ҩ��������\n",
//        (:random_move:)
    	}));
        setup();
        add_money("silver", 20);
set("inquiry", ([
"name": "���¾��Ƕ����У�\n",
"here": "��������������������������(lianzhi)���ֶ�ҩ��\n",
"��ҩ": "���¿���ʹ��(lianzhi)�������Ƹ��ֶ�ҩ��\n",
"����": (: ask_me :),
"�䷽": (: ask_me :),
"��ҩ�䷽": (: ask_me :),
]) );
        carry_object("/d/wudang/obj/greenrobe")->wear();
}
int ask_me()
{
        object ob,me,book;
        me = this_player();
        if ((string)me->query("family/family_name") != "�嶾��")    
              return notify_fail("�����뱾�ɲ���ԨԴ�����Ǵ����ﻰ����\n");
        book=present("jing",me);
        if(objectp(book) && (string)book->query("name")=="������ƪ")
              return notify_fail("�㲻����һ��������ô����Ҫ��\n");
        command("say �������嶾��֮����������ǧ�򲻿���ʧ�˰���\n");
        ob = new(__DIR__"obj/dujing1");
        ob->move(this_player());
 //       return "��ȥ�ɡ�";
         return 1;
}
