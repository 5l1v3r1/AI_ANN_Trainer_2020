#include <time.h>
#include "samson.h"
#include "ann_trainer.h"

void help(void)
{
    my_putstr("\n\tHELP:\n\nThis program is a Artificial Neural Network trai");
    my_putstr("ner.\nThe ANN_Trainer will improve your model for you by adju");
    my_putstr("sting his weights.\nThe ANN_Trainer need an ANN_LOG, an Input");
    my_putstr("_FILE, and a Output_File.\n\n*The ANN_LOG can be obtain with ");
    my_putstr("sms_write_log_file function.\n*The Input_File and Output_File");
    my_putstr(" are your dataset split in two file : Input and Output set\n");
    my_putstr("\n\tUSAGE:\n\n./ann_trainer -m [ANN_LOG] -i [Input_File] -n ");
    my_putstr("[nb input] -o [Output_file]\n\n\n");
}

char *find_args(char *to_find, char **argv)
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (argv[i][0] != '\0' && argv[i][0] != to_find[0])
            continue;
        if (argv[i][1] != '\0' && argv[i][1] == to_find[1]
        && argv[i][2] == '\0')
            return (argv[i + 1]);
    }
    return (NULL);
}



int init_ann_trainer(int argc, char **argv, ann_trainer_t *trainer)
{
    trainer->ann_log_name = find_args("-m", argv);
    trainer->ann_input_name = find_args("-i", argv);
    trainer->ann_output_name = find_args("-o", argv);
    trainer->nb_input = my_str_to_digit(find_args("-n", argv));

    if (trainer->ann_log_name == NULL
    || trainer->ann_input_name == NULL
    || trainer->ann_output_name == NULL)
        return (ERROR);
    trainer->ann = my_file_to_dbl_array(trainer->ann_log_name, ':');
    trainer->input_user = my_file_to_dbl_array(trainer->ann_input_name, ':');
    trainer->output_user = my_file_to_dbl_array(trainer->ann_output_name, ':');
    if (trainer->ann == NULL
    || trainer->input_user == NULL
    || trainer->output_user == NULL)
        return (ERROR);
    trainer->output_ann = NULL;
    return (SUCCESS);
}

void free_ann_trainer(ann_trainer_t *ann_trainer)
{

    if (ann_trainer->input_user != NULL && ann_trainer->input_user[0] != NULL)
        sms_free_csv(ann_trainer->input_user);
    if (ann_trainer->output_ann != NULL && ann_trainer->output_ann[0] != NULL)
        sms_free_csv(ann_trainer->output_ann);
}

int main(int argc, char **argv)
{
    ann_trainer_t ann_trainer = {NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, 0};

    if (argc < 9) {
        help();
        return (SUCCESS);
    }
    init_ann_trainer(argc, argv, &ann_trainer);
    brain(&ann_trainer);
    return (SUCCESS);
}