<?php

function go_live_admin() {
  $module_not_exist = '<span class="admin-missing">Not installed</span>';
  
  $go_live_checklist = variable_get('go_live_checklist', array());
  
  $form['checklist'] = array(
    'intro' => array(
      '#markup' => t('Check these options as you complete each one. This will help organize what has been completed and what still needs to be done to make the site completely ready for production use.'),
    ),
    'go_live' => array(
      '#type' => 'vertical_tabs',
      'path_redirection' => array(
        '#type' => 'fieldset',
        '#title' => t('Path Redirection'),
        'redirect' => array(
          '#type' => 'checkbox',
          '#title' => t('All paths from old website have been redirected with <strong>Redirect</strong>') . ' - ' . (module_exists('redirect') ? l('Configuration Page', 'admin/config/search/redirect', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['redirect'],
          '#attributes' => (!module_exists('redirect') ? array('disabled' => 'disabled') : ''),
        ),
        'global_redirect' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>Global Redirect</strong> module is configured correctly') . ' - ' . (module_exists('globalredirect') ? l('Configuration Page', 'admin/config/system/globalredirect', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['global_redirect'],
          '#attributes' => (!module_exists('globalredirect') ? array('disabled' => 'disabled') : ''),
        ),
      ),
      'quickbar' => array(
        '#type' => 'fieldset',
        '#title' => t('Quickbar'),
        'quickbar_menu_items' => array(
          '#type' => 'checkbox',
          '#title' => t('All <strong>Quickbar menu items</strong> have been verified and are functional') . ' - ' . (module_exists('quickbar') ? l('Configuration Page', 'admin/config/user-interface/quickbar', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['quickbar_menu_items'],
          '#attributes' => (!module_exists('quickbar') ? array('disabled' => 'disabled') : ''),
        ),
        'quickbar_user_roles' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>Quickbar user roles</strong> have been configured correctly') . ' - ' . (module_exists('quickbar') ? l('Configuration Page', 'admin/config-userinterface/quickbar', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['quickbar_user_roles'],
          '#attributes' => (!module_exists('quickbar') ? array('disabled' => 'disabled') : ''),
        ),
        'quickbar_help' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>Quickbar help</strong> has been setup for all necessary pages') . ' - ' . (module_exists('quickbar') ? l('Configuration Page', 'admin/config/user-interface/quickbar', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['quickbar_help'],
          '#attributes' => (!module_exists('quickbar_help') ? array('disabled' => 'disabled') : ''),
        ),
      ),
      'misc_contrib_modules' => array(
        '#type' => 'fieldset',
        '#title' => t('Misc. Contributed Modules'),
        'xmlsitemap' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>XML Sitemap</strong> is completely configured') . ' - ' . (module_exists('xmlsitemap') ? l('Configuration Page', 'admin/config/search/xmlsitemap', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['xmlsitemap'],
          '#attributes' => (!module_exists('xmlsitemap') ? array('disabled' => 'disabled') : ''),
        ),
        'db_maintenance' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>DB Maintenance</strong> has all necessary databases selected to be optimized') . ' - ' . (module_exists('db_maintenance') ? l('Configuration Page', 'admin/config/system/db_maintenance', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['db_maintenance'],
          '#attributes' => (!module_exists('db_maintenance') ? array('disabled' => 'disabled') : ''),
        ),
        'linkchecker' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>Linkchecker</strong> has been configured properly') . ' - ' . (module_exists('linkchecker') ? l('Configuration Page', 'admin/settings/linkchecker', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#description' => t('CURRENTLY NOT AVAILABLE FOR DRUPAL 7!'),
          '#default_value' => $go_live_checklist['linkchecker'],
          '#attributes' => (!module_exists('linkchecker') ? array('disabled' => 'disabled') : ''),
        ),
        'metatags' => array(
          '#type' => 'checkbox',
          '#title' => t('<strong>Meta tags</strong> (nodewords) have been setup on all necessary pages') . ' - ' . (module_exists('metatags') ? l('Configuration Page', 'admin/content/nodewords', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#description' => t('CURRENTLY NOT AVAILABLE FOR DRUPAL 7!'),
          '#default_value' => $go_live_checklist['metatags'],
          '#attributes' => (!module_exists('metatags') ? array('disabled' => 'disabled') : ''),
        ),
        'webform_email_configured' => array(
          '#type' => 'checkbox',
          '#title' => t('All <strong>webforms</strong> are setup to send email to the appropriate address(es)'),
          '#default_value' => $go_live_checklist['webform_email_configured'],
        ),
      ),
      'users' => array(
        '#type' => 'fieldset',
        '#title' => t('Users'),
        'appropriate_users' => array(
          '#type' => 'checkbox',
          '#title' => t('All necessary <strong>users</strong> are setup and configured') . ' - ' . l('Configuration Page', 'admin/user/user', array(attributes => array('target' => '_blank'))),
          '#default_value' => $go_live_checklist['appropriate_users'],
        ),
      ),
      'browsers' => array(
        '#type' => 'fieldset',
        '#title' => t('Browsers'),
        'internet_exploder' => array(
          '#type' => 'fieldset',
          '#title' => t('Internet Exploder'),
          'ie9_compatible' => array(
            '#type' => 'checkbox',
            '#title' => t('<strong>Internet Exploder 9</strong> has been tested and is rendering all elements correctly'),
            '#default_value' => $go_live_checklist['ie9_compatible'],
          ),
          'ie8_compatible' => array(
            '#type' => 'checkbox',
            '#title' => t('<strong>Internet Exploder 8</strong> has been tested and is rendering all elements correctly'),
            '#default_value' => $go_live_checklist['ie8_compatible'],
          ),
          'ie7_compatible' => array(
            '#type' => 'checkbox',
            '#title' => t('<strong>Internet Exploder 7</strong> has been tested and is rendering all elements correctly'),
            '#default_value' => $go_live_checklist['ie7_compatible'],
          ),
        ),
        'safari' => array(
          '#type' => 'fieldset',
          '#title' => t('Safari'),
          'safari5_compatible' => array(
            '#type' => 'checkbox',
            '#title' => t('<strong>Safari 5</strong> has been tested and is rendering all elements correctly'),
            '#default_value' => $go_live_checklist['safari5_compatible'],
          ),
        ),
        'chrome' => array(
          '#type' => 'fieldset',
          '#title' => t('Chrome'),
          'chrome_compatible' => array(
            '#type' => 'checkbox',
            '#title' => t('<strong>Chrome</strong> has been tested and is rendering all elements correctly'),
            '#default_value' => $go_live_checklist['chrome_compatible'],
          ),
        ),
      ),
      'google' => array(
        '#type' => 'fieldset',
        '#title' => t('Google'),
        'google_webmaster_tools' => array(
          '#type' => 'checkbox',
          '#title' => t('This site is setup on <strong>Google Webmaster Tools</strong>') . ' - ' . l('Google Webmaster Page', 'https://www.google.com/webmasters/tools/home?hl=en', array(attributes => array('target' => '_blank'))),
          '#default_value' => $go_live_checklist['google_webmaster_tools'],
        ),
        'google_analytics' => array(
          '#type' => 'checkbox',
          '#title' => t('This site is setup on <strong>Google Analytics</strong>') . ' - ' . l('Google Analytics Page', 'https://www.google.com/analytics', array(attributes => array('target' => '_blank'))) . ' | ' . (module_exists('googleanalytics') ? l('Configuration Page', 'admin/settings/googleanalytics', array(attributes => array('target' => '_blank'))) : $module_not_exist),
          '#default_value' => $go_live_checklist['google_analytics'],
          '#attributes' => (!module_exists('googleanalytics') ? array('disabled' => 'disabled') : ''),
        ),
      ),
      'miscellaneous' => array(
        '#type' => 'fieldset',
        '#title' => t('Miscellaneous'),
        'favicon' => array(
          '#type' => 'checkbox',
          '#title' => t('A <strong>favicon</strong> has been setup for this site') . ' - ' . l('Configuration Page', 'admin/build/themes/settings/' . variable_get('theme_default', '')),
          '#default_value' => $go_live_checklist['favicon'],
        ),
        'cronjob' => array(
          '#type' => 'checkbox',
          '#title' => t('This site has a maintenance <strong>cron job</strong> setup on the server'),
          '#description' => t('Example: <code>0  *  *  *  *  wget -O - -q -t 1 http://' . $_SERVER['HTTP_HOST'] . '/cron.php</code>'),
          '#default_value' => $go_live_checklist['cronjob'],
        ),
        'yslow' => array(
          '#type' => 'checkbox',
          '#title' => t("Checked site's performance score with YSlow"),
          '#default_value' => $go_live_checklist['yslow'],
        ),
      ),
    ),
  );
 
  $form['submit']['update_checklist'] = array(
    '#type' => 'submit',
    '#value' => 'Update Checklist',
  );

  // If the site has already been made live, we don't want to show this button
  if (!variable_get('go_live_is_live', 0)) {
    $form['submit']['go_live'] = array(
      '#type' => 'submit',
      '#value' => 'Go Live!',
    );

    $form['submit']['description'] = array(
      '#markup' => t("Clicking 'Go Live!' will configure settings on the site to be optimized for production sites. <strong>Only click 'Go Live!' if you are <u>really</u> ready to make this site live.</strong><br>Also, any changes made to the checklist options will be updated."),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
  }
  else {
    drupal_set_message('This site has already been set to Go Live! You may still update your checklist settings below.', 'warning');
  }
 
  $form['checklist']['#pre_render'][] = 'vertical_tabs_form_pre_render';
  $form['#submit'][] = 'go_live_admin_submit';
  
  return $form;
}


function go_live_admin_submit(&$form, &$form_state) {
  if($form_state['clicked_button']['#value'] == 'Go Live!') {
    // Once we have selected to 'Go Live!' we set this variable so that we know and can configure the
    // the configuration screen (and maybe other things in the future)
    variable_set('go_live_is_live', 1);
    
    /**
     * LESS CSS Preprocessor module
     ************************************/
    // Set the LESS CSS Preprocessor development mode to false
    if(module_exists('less')) {
      variable_set('less_devel', 0);
    }
    
    
    /**
     * Pathauto module
     ************************************/
    if(module_exists('pathauto')) {
      variable_set('pathauto_update_action', '1');
    }
    
    /**
     * Performance Page Settings
     ************************************/
    // Enable caching
    variable_set('cache', '1');
    
    // Enable page compression
    variable_set('page_compression', '1');
    
    // Enable block caching
    variable_set('block_cache', '1');
    
    // Set CSS aggregation to be fully optimized and enable gzip compression
    variable_set('preprocess_css', '1');
    variable_set('css_gzip', 1);
    
    // Set JS aggregation to be enabled and enable gzip compression
    variable_set('preprocess_js', '1');
    variable_set('javascript_aggregator_gzip', 1);
    
    
    /**
     * Theme settings
     ************************************/
    $theme_settings = variable_get('theme_' . variable_get('theme_default', '') . '_settings', '');
    // Disable theme registry from constantly being rebuilt
    $theme_settings['zen_rebuild_registry'] = 0;
    variable_set('theme_' . variable_get('theme_default', '') . '_settings', $theme_settings);
    
    
    /**
     * Disable the following modules
     ************************************/
    $disable = array(
      'context_ui',
      'devel',
      'dev_banner',
      'drupalforfirebug',
      'drupalforfirebug_preprocess',
      'gridder',
      'help',
      'permission_select',
      'views_ui',
      'zenophile_custom',
      'zenophile_sidebars',
      'zenophile',
    );
    module_disable($disable);
    
    drupal_set_message('The site has been set for production use!');
  }
  
  $checklist_items = array();
  foreach ($form_state['values'] as $key => $value) {
    switch($key){
      case 'op':
      case 'go_live':
      case 'update_checklist':
      case 'form_build_id':
      case 'form_token':
      case 'form_id':
        // Is there a better way to implement this?
        break;
      default:
        $checklist_items[$key] = $value;
    }
  }
  
  variable_set('go_live_checklist', $checklist_items);
  
  if($form_state['clicked_button']['#value'] == 'Update Checklist') {
    drupal_set_message('The checklist settings have been updated');
  }
}


function go_live_settings() {
  $form['info'] = array(
    '#markup' => t("This will configure settings on the site to be optimized for production sites. Only click 'Go Live!' below if you are really ready to make this site live."),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );
  
  return $form;
}
