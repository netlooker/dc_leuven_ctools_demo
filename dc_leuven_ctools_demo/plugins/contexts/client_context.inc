<?php

/**
 * @file
 * Plugin to provide Client context
 */

/**
 * Definition of the plugin
 */
$plugin = array(
  'title' => t('Demo | Client Context'),
  'description' => t('Provides variables which are related to Client.'),
  'context' => 'client_context_create',
  'context name' => 'client_context',
  'keyword' => 'client_context',
  'convert list' => 'client_context_convert_list',
  'convert' => 'client_context_convert',
);

/**
 * Main function for creating context data
 * @param $empty
 * @param null $data
 * @param bool|FALSE $conf
 * @return \ctools_context
 */
function client_context_create($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('client_context');
  $context->plugin = 'client_context';

  if ($empty) {
    return $context;
  }

  $context->title = 'Client context';
  $context->data = new stdClass();

  // Fetching data from currently logged in user
  global $user;
  $user_account = user_load($user->uid);
  $user_wrapper = entity_metadata_wrapper('user', $user_account);
  $context->data->uid = $user->uid;
  $context->data->name = $user_wrapper->field_client_name->value();
  $context->data->last_name = $user_wrapper->field_client_last_name->value();
  $context->data->age = $user_wrapper->field_client_age->value();
  $context->data->subscription_nid = $user_wrapper->field_subscription_reference->value()->nid;
  $context->data->subscription_title = $user_wrapper->field_subscription_reference->value()->title;

  return $context;
}

/**
 * Helper function which returning list of values which are exposed
 * @return array
 */
function client_context_convert_list() {
  return array(
    'uid' => t('Client User ID'),
    'name' => t('Client name'),
    'last_name' => t('Client last name'),
    'age' => t('Client age'),
    'subscription_nid' => t('Subscription Node ID'),
    'subscription_title' => t('Subscription Node Title'),
  );
}

/**
 * Helper function for returning a string for each of the exposed sub-keywords.
 * @param $context
 * @param $type
 * @return mixed
 */
function client_context_convert($context, $type) {
  switch ($type) {
    case 'uid':
      return $context->data->uid;
    case 'name':
      return $context->data->name;
    case 'last_name':
      return $context->data->last_name;
    case 'age':
      return $context->data->age;
    case 'subscription_nid':
      return $context->data->subscription_nid;
    case 'subscription_title':
      return $context->data->subscription_title;
  }
}