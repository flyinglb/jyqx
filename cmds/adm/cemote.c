//debug cmd

inherit F_SAVE;
mapping Emotes;
int main(object me, string arg)
{
        mapping oe, em;
        string *es;
        int i, i1;
        oe = EMOTE_D->query_emotes();
        es = keys(oe);
        Emotes = allocate_mapping(sizeof(es));
        for(i=0,i1=sizeof(es);i<i1;i++) {
                em = allocate_mapping(8);
                em["unknow_target_myself_msg"] = oe[es[i]]["myself"];
                em["unknow_target_others_msg"] = oe[es[i]]["others"];
                em["myself_target_myslef_msg"] = oe[es[i]]["myself_self"];
                em["myself_target_others_msg"] = oe[es[i]]["others_self"];
                em["others_target_myslef_msg"] = oe[es[i]]["myself_target"];
                em["others_target_others_msg"] = oe[es[i]]["target"];
                em["others_target_target_msg"] = oe[es[i]]["others_target"];
                em["updated"] = oe[es[i]]["updated"];
                Emotes[es[i]] = em;
        }
        if(!save())
                write("Save Error.\n");
        else    write("Down.\n");
        return 1;
}

string query_save_file() { return DATA_DIR + "emote"; }

