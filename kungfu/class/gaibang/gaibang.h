// gaibang.h for fight and get ������
//Last Modify By Byp@MX 2000/11/28
//Note: �޸������� BUG

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");

        if (!my_fam || (my_fam["family_name"] != "ؤ��"))
                return notify_fail("���������������\n");

        if ( ob->query_temp("have_cloth") && present("po bu", ob) )
        {
                command("say �㲻���Ѿ����Ʋ�ô?");
                return 0;
        }

        if (((ob->query("beggarlvl") == 0) &&
             (ob->query("combat_exp") <= 500)) ||
            ((ob->query("beggarlvl") == 1) &&
             (ob->query("combat_exp") <= 1000)) ||
            ((ob->query("beggarlvl") == 2) &&
             (ob->query("combat_exp") <= 3000)) ||
            ((ob->query("beggarlvl") == 3) &&
             (ob->query("combat_exp") <= 5000)) ||
            ((ob->query("beggarlvl") == 4) &&
             (ob->query("combat_exp") <= 10000)) ||
            ((ob->query("beggarlvl") == 5) &&
             (ob->query("combat_exp") <= 15000)) ||
            ((ob->query("beggarlvl") == 6) &&
             (ob->query("combat_exp") <= 20000)) ||
            ((ob->query("beggarlvl") >= 7) &&
             (ob->query("combat_exp") <= 30000)))
        {
             command("say �����ǵ�ŧˮ���ҿ������˰ɡ�\n");
             return 1;
        }
        if (((ob->query("beggarlvl") == 0) &&
             (me->query("title") == "ؤ��һ������")) ||
            ((ob->query("beggarlvl") == 1) &&
             (me->query("title") == "ؤ���������")) ||
            ((ob->query("beggarlvl") == 2) &&
             (me->query("title") == "ؤ����������")) ||
            ((ob->query("beggarlvl") == 3) &&
             (me->query("title") == "ؤ���Ĵ�����")) ||
            ((ob->query("beggarlvl") == 4) &&
             (me->query("title") == "ؤ���������")) ||
            ((ob->query("beggarlvl") == 5) &&
             (me->query("title") == "ؤ����������")) ||
            ((ob->query("beggarlvl") == 6) &&
             (me->query("title") == "ؤ���ߴ�����")) ||
            ((ob->query("beggarlvl") == 7) &&
             (me->query("title") == "ؤ��˴�����")) ||
            ((ob->query("beggarlvl") == 8) &&
             (me->query("title") == "ؤ��Ŵ�����")))
        {
          if((obj->query("id") == "qingzhu ling")
            && !ob->query_temp("have_cloth"))
          {
             ob->set_temp("fight_ok",1);
             ob->set_temp("beggar_fight_id",me->query("id"));
             //add by Byp, Note:�޸�������BUG
             command("say �ã���Ȼ����������ǾͿ���������ˡ�\n");
             remove_call_out("destroying");
             call_out("destroying", 1, me, obj);
             return 1;
          }
       }
       command("smile");
       command("say ������Ȼֻ������������Ҳ�ǲ��еġ�\n");
       command("say �ⶫ�����㻹���Լ����Űɡ�\n");
       command("give " + obj->query("id") + " to " + me->query("id"));
       return 0;
}

void destroying(object me, object obj)
{
        if(!obj) return;
        obj->move(VOID_OB);
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;
        //add by Byp, Note:�޸�������BUG
        if (ob->query_temp("beggar_fight_id") != me->query("id")) return 0;
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        //add by Byp, Note:�޸�������BUG
        ob->delete_temp("beggar_fight_id");
        return 1;
}

int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1;

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say ��ү��������ã�����������������Ʋ��Ҽ���ȥ !\n");
                message_vision("$N����$nһ���Ʋ���\n", me, ob);
                ob->set("newtitle",me->query("title"));
                ob->set_temp("have_cloth",1);
                obj=new(__DIR__"obj/po-bu");
                obj->move(ob);
                return 1;
        }

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say ����" + RANK_D->query_respect(ob) +
                "��������Ҳ�������Լҳ��˼���ë !\n");
                return 1;
        }
        return 1;
}
